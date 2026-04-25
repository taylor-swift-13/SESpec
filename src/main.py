import re
import sys
import logging
import os 
import shutil
import time
import argparse
import json
from datetime import datetime
from pathlib import Path
from uuid import uuid4

from typing import List,Dict, Tuple, Optional, Union
from LoopInvGen.inv_gen import InvGenerator
from Utils.create_post_condition import create_post, update_annotation
from Utils.extract_all import function_info_init,free_all_tu
from Utils.main_class import *
from Utils.remove_macro import process_all_c_files
from specification_verify import SpecVerifier
from config import MainConfig,LLMConfig
from convertor import SpecificationConvertor
from spec_gen import SpecGenerator
from DSL.Q2D import Post2DSL
from pre_cond_manager import PreconditionsManager
from config_loader import load_config_from_file
from llm import get_token_stats, reset_token_stats

SRC_ROOT = Path(__file__).resolve().parent



def parse_arguments():
    """Parse command line arguments"""
    parser = argparse.ArgumentParser(description='ASGSE - Run with configuration file')
    parser.add_argument('--config', '-c', 
                       type=str, 
                       default='configs/func_config.json',
                       help='Configuration file path (supports .json and .yaml formats)')
    parser.add_argument('--root-dir', '-r',
                       type=str,
                       help='Root directory (overrides config file setting)')
    parser.add_argument('--function', '-f',
                       type=str,
                       help='Function name (overrides config file setting)')
    return parser.parse_args()


def run_from_config(config_path: str, function_name: str = None, root_dir: str = None, debug: bool = None):
    """
    Run analysis from configuration file
    
    Args:
        config_path (str): Configuration file path
        function_name (str, optional): Function name to analyze
        root_dir (str, optional): Project root directory
        debug (bool, optional): Whether to enable debug mode
    """
    processor = None
    try:
        # Load configuration file
        main_config, preconditions, llm_config = load_config_from_file(config_path)
        
        # Apply command line argument overrides
        if function_name:
            main_config.function_name = function_name
        if root_dir:
            main_config.root_dir = root_dir
        if debug is not None:
            main_config.debug = debug
    
        # Validate required parameters
        if not main_config.function_name:
            raise ValueError("Must specify function name to generate specification (via config file or --function parameter)")
        if not main_config.root_dir:
            raise ValueError("Must specify project root directory (via config file or --root-dir parameter)")
        
        print(f"🚀 Starting specification generation for function: {main_config.function_name}")
        print(f"📁 Project directory: {main_config.root_dir}")
        print(f"📄 Configuration file: {config_path}")
        print(f"🤖 Using model: {llm_config.api_model}")
        
        # Create processor and run analysis
        processor = FunctionProcessor(main_config, preconditions, llm_config)
        processor.run_analysis()
        print(f"📦 Workspace: {processor.config.workspace_root}")
        
        print("✅ Generation completed!")
        
    except Exception as e:
        if processor is not None:
            processor.end_time = time.time()
            if processor.first_pass is None:
                processor.first_pass = {
                    "syntax": 0,
                    "valid": 0,
                    "satisfy": 0,
                    "syntax_status": "fail",
                    "validity_status": "fail",
                    "satisfy_status": "fail",
                    "failure_reason": str(e),
                    "mode": "exception",
                }
            if getattr(processor, "logger", None):
                processor.logger.exception("Run failed")
            if processor.config.workspace_root:
                try:
                    processor._write_run_summary()
                except Exception:
                    pass
        print(f"❌ Run failed: {e}")
        sys.exit(1)


def _setup_analysis_logger(
    function_name: str,
    log_dir: str,
    debug: bool = False,
    to_console: bool = True,
    log_filename: str = None,
) -> logging.Logger:
    """
    Configure and return an independent logger for specific function analysis tasks.
    Logs will be written to both file and console (if to_console is True).
    File logs include complete prefix, console logs do not include prefix.
    """
    # Ensure the log directory exists
    os.makedirs(log_dir, exist_ok=True)
    log_file_path = os.path.join(log_dir, log_filename or f'{function_name}.log')

    # Get or create the logger instance named after the function
    logger = logging.getLogger(function_name)

    # Clear any existing handlers to prevent duplicate output
    if logger.hasHandlers():
        logger.handlers.clear()

    # Set the logger's overall level
    logger.setLevel(logging.DEBUG if debug else logging.INFO)
    
    # Prevent propagation to the root logger to avoid duplicate output
    logger.propagate = False

    # --- Formatter for File Output (with prefix) ---
    file_formatter = logging.Formatter('%(asctime)s - %(levelname)s  - %(message)s')

    # --- Formatter for Console Output (no prefix) ---
    console_formatter = logging.Formatter('%(message)s') # Only the message, no prefix

    # 1. Add File Handler
    file_handler = logging.FileHandler(log_file_path, mode='w', encoding='utf-8')
    file_handler.setLevel(logging.DEBUG if debug else logging.INFO) # File gets all debug info if debug_mode is on
    file_handler.setFormatter(file_formatter) # Use the file-specific formatter
    logger.addHandler(file_handler)

    # 2. Add Console Handler (if enabled)
    if to_console:
        console_handler = logging.StreamHandler(sys.stdout)
        # Console usually gets INFO level and above for clarity
        console_handler.setLevel(logging.INFO) 
        console_handler.setFormatter(console_formatter) # Use the console-specific formatter
        logger.addHandler(console_handler)

    return logger



class FunctionProcessor:
    """Main function processing class"""
    
    def __init__(self, config: MainConfig,preconditions: Dict[str, Union[str, Tuple[str, Optional[str]]]] = None, llm_config: LLMConfig = None) -> None:
        """Main processor constructor
        
        Args:
            config (MainConfig): Analyzer configuration object
        
        Raises:
            ValueError: When Input configuration is invalid
        """
        if not isinstance(config, MainConfig):
            raise ValueError("Invalid config type")
    
        self.config = config
        self.global_type_info_dict: Dict = {}
        self.tu_dict: Dict = {}
        self.file_cache: Dict = {}
        self.conds : List[str] = []
        self.function_info_list: List[FunctionInfo] = []
        self.llm_config = llm_config or LLMConfig(api_model='gpt-4o')
        self.pending_functions: List[str] = []
        self.top_function_info = None
        self.first_pass = None
        self.preconditions = preconditions
        self.precond_manager = None
        self.pass_count = self.config.pass_count
        
        # Timing related attributes
        self.start_time = None
        self.end_time = None
        
        # 重置 token 统计（开始新的分析时）
        reset_token_stats()
        self._initialize_runtime_paths()

        # Initialize dual-path Output
        self.logger = _setup_analysis_logger(
                function_name=self.config.function_name,
                log_dir=self.config.log_dir, 
                debug=self.config.debug, 
                to_console=True,
                log_filename="run.log",
            )
        self.logger.info(f"workspace_root={self.config.workspace_root}")

    def _resolve_path(self, path: str) -> Path:
        raw = Path(path)
        return raw if raw.is_absolute() else SRC_ROOT / raw

    def _extract_function_names(self, source_file: Path) -> List[str]:
        text = source_file.read_text(encoding="utf-8", errors="ignore")
        pattern = re.compile(
            r"^\s*(?:(?:static|inline|extern|const|volatile|register|signed|unsigned|long|short)\s+)*"
            r"(?:void|int|char|float|double|long|short|unsigned|signed|bool|_Bool|size_t|struct\s+\w+|enum\s+\w+|union\s+\w+)"
            r"(?:\s+|\s*\*+\s*)([A-Za-z_][A-Za-z0-9_]*)\s*\([^;{}]*\)\s*\{",
            re.MULTILINE,
        )
        return [name for name in pattern.findall(text) if name != "unknown"]

    def _validate_case_function_uniqueness(self, source_root: Path) -> None:
        function_to_files: Dict[str, set[str]] = {}
        for source_file in sorted(source_root.rglob("*.c")):
            for function_name in self._extract_function_names(source_file):
                function_to_files.setdefault(function_name, set()).add(str(source_file))

        conflicts = {
            function_name: sorted(files)
            for function_name, files in function_to_files.items()
            if len(files) > 1
        }
        if not conflicts:
            return

        conflict_lines = []
        for function_name, files in sorted(conflicts.items()):
            conflict_lines.append(f"{function_name}: {', '.join(files)}")
        raise ValueError(
            "Duplicate function names detected under input case "
            f"{source_root}: {'; '.join(conflict_lines)}"
        )

    def _initialize_runtime_paths(self) -> None:
        run_id = self.config.run_id or f"{datetime.now().strftime('%Y%m%d_%H%M%S')}_{os.getpid()}_{uuid4().hex[:8]}"
        self.config.run_id = run_id
        log_root = self._resolve_path(self.config.log_dir)
        workspace_root = (
            log_root
            / self.config.root_dir
            / self.llm_config.api_model
            / self.config.function_name
            / run_id
        )
        self.config.workspace_root = str(workspace_root)
        self.config.annotated_c_file_path = str(workspace_root / "1_output")
        self.config.annotated_loop_c_file_path = str(workspace_root / "2_output")
        self.config.generated_loop_c_file_path = str(workspace_root / "3_output")
        self.config.output_path = str(workspace_root / "output")
        self.config.log_dir = str(workspace_root)
        self.config.loop_run_path = str(workspace_root / "loop")
        self.config.goal_run_path = str(workspace_root / "goal")
        self.config.tmp_run_path = str(workspace_root / "tmp")

        input_base = self._resolve_path(self.config.input_dir)
        source_root = input_base if input_base.name == self.config.root_dir and input_base.exists() else input_base / self.config.root_dir
        self._validate_case_function_uniqueness(source_root)
        self.config.input_path = str(source_root)

        for path in [
            workspace_root,
            Path(self.config.annotated_c_file_path),
            Path(self.config.annotated_loop_c_file_path),
            Path(self.config.generated_loop_c_file_path),
            Path(self.config.output_path),
            Path(self.config.loop_run_path),
            Path(self.config.goal_run_path),
            Path(self.config.tmp_run_path),
        ]:
            path.mkdir(parents=True, exist_ok=True)
        self._copy_runtime_support_files(workspace_root)

    def _copy_runtime_support_files(self, workspace_root: Path) -> None:
        runtime_support_dir = SRC_ROOT / "runtime_support"
        for support_name in [
            "verification_stdlib.h",
            "verification_list.h",
            "int_array_def.h",
            "common.strategies",
            "int_array.strategies",
        ]:
            source = runtime_support_dir / support_name
            if source.exists():
                shutil.copy2(source, workspace_root / support_name)

    def _log_overall_timing(self):
        """Log overall timing information"""
        if self.start_time and self.end_time:
            total_duration = self.end_time - self.start_time
            self.logger.info("="*50)
            self.logger.info("⏰ OVERALL EXECUTION TIME STATISTICS")
            self.logger.info(f"Total execution time: {total_duration:.2f} seconds ({total_duration/60:.2f} minutes)")
            self.logger.info("="*50)
    
    def _log_token_stats(self):
        """Log token usage statistics"""
        stats = get_token_stats()
        self.logger.info("="*50)
        self.logger.info("📊 TOKEN USAGE STATISTICS")
        self.logger.info(f"Total API calls: {stats['call_count']}")
        self.logger.info(f"Total prompt tokens (input): {stats['total_prompt_tokens']:,}")
        self.logger.info(f"Total completion tokens (output): {stats['total_completion_tokens']:,}")
        self.logger.info(f"Total tokens: {stats['total_tokens']:,}")
        if stats['call_count'] > 0:
            avg_prompt = stats['total_prompt_tokens'] / stats['call_count']
            avg_completion = stats['total_completion_tokens'] / stats['call_count']
            avg_total = stats['total_tokens'] / stats['call_count']
            self.logger.info(f"Average prompt tokens per call: {avg_prompt:.1f}")
            self.logger.info(f"Average completion tokens per call: {avg_completion:.1f}")
            self.logger.info(f"Average total tokens per call: {avg_total:.1f}")
        self.logger.info("="*50)
        return stats

    def _write_run_summary(self) -> None:
        total_seconds = (self.end_time - self.start_time) if self.start_time and self.end_time else 0.0
        stats = get_token_stats()
        source_file = getattr(self.top_function_info, "file_path", None)
        summary = {
            "workspace_root": self.config.workspace_root,
            "run_id": self.config.run_id,
            "root_dir": self.config.root_dir,
            "function_name": self.config.function_name,
            "model": self.llm_config.api_model,
            "source_file": source_file,
            "only_loop": self.config.only_loop,
            "first_pass": self.first_pass,
            "total_seconds": total_seconds,
            "token_stats": stats,
            "paths": {
                "input": self.config.input_path,
                "annotated_c": self.config.annotated_c_file_path,
                "annotated_loop": self.config.annotated_loop_c_file_path,
                "generated_loop": self.config.generated_loop_c_file_path,
                "output": self.config.output_path,
                "log": str(Path(self.config.workspace_root) / "run.log"),
                "loop": self.config.loop_run_path,
                "goal": self.config.goal_run_path,
                "tmp": self.config.tmp_run_path,
            },
        }
        summary_path = Path(self.config.workspace_root) / "run_summary.json"
        summary_path.write_text(json.dumps(summary, indent=2, ensure_ascii=False), encoding="utf-8")

        latest_path = summary_path.parent.parent / "latest.json"
        latest_payload = {
            "run_id": self.config.run_id,
            "workspace_root": self.config.workspace_root,
            "root_dir": self.config.root_dir,
            "function_name": self.config.function_name,
            "model": self.llm_config.api_model,
            "source_file": source_file,
        }
        latest_path.write_text(json.dumps(latest_payload, indent=2, ensure_ascii=False), encoding="utf-8")

        
        

    def _prepare_workspace(self):
        """Preprocess workspace directory (macro processing)"""
      
        process_all_c_files(self.config.root_dir,self.config.input_path)
        

    def _initialize_function(self, func_name: str) -> FunctionInfo:
        """Initialize single function information"""
        func = function_info_init(
            self.tu_dict,
            self.config.input_path,
            func_name,
            self.file_cache,
            self.global_type_info_dict
        )
        self._disable_recursive_callee_expansion(func)
        return func

    def _disable_recursive_callee_expansion(self, func: FunctionInfo) -> None:
        """Stop callee expansion for directly recursive functions."""
        is_recursive_function = func.name in func.callee_set
        setattr(func, "is_recursive_function", is_recursive_function)
        if is_recursive_function:
            self.logger.info(
                f"Recursive function detected for {func.name}; stop expanding callees and keep the rest of the workflow unchanged."
            )
            func.callee_set = set()

    def _is_recursive_function(self, func: FunctionInfo) -> bool:
        return bool(getattr(func, "is_recursive_function", False))

    def _parameter_involves_memory(self, parameter: Parameter) -> bool:
        if parameter.is_ptr or parameter.array_length != -1 or parameter.is_struct:
            return True
        if isinstance(parameter.type, StructInfo):
            return any(self._parameter_involves_memory(member) for member in parameter.type.parameter_list)
        return False

    def _is_plain_int_parameter(self, parameter: Parameter) -> bool:
        if self._parameter_involves_memory(parameter):
            return False
        return str(parameter.type).strip() == "int"

    def _should_skip_contract_generation(self, func: FunctionInfo) -> bool:
        if any(self._parameter_involves_memory(parameter) for parameter in func.parameter_list):
            return False
        if not all(self._is_plain_int_parameter(parameter) for parameter in func.parameter_list):
            return False
        return func.func_type.strip() == "void" or func.name == "main"
    
    


    def _process_new_function(self, func_name: str):
        """Process newly discovered functions"""
        self.logger.info(f'Now processing function {func_name}\n')
        if 'unknown' in func_name:
            return UNKNOWN_FUNCTION(func_name)
        else:
            new_func = self._initialize_function(func_name)

        if func_name in self.precond_manager.requires:
            new_func.require = self.precond_manager.requires[func_name]


        self.function_info_list.append(new_func)
        self.pending_functions.append(func_name)
        self.pending_functions.extend(new_func.callee_set)

    def __generate_loop_invariant(self, func: FunctionInfo):
        generator = SpecGenerator(
                func,
                self.function_info_list,
                self.global_type_info_dict,
                self.config,
                self.logger,
                self.llm_config,
                self.precond_manager
        )

        generator.create_generated_c_file()

        if self._is_recursive_function(func):
            self.logger.info(
                f"Recursive function {func.name}: skip automatic annotation/symbolic execution/translation and generate ACSL directly by LLM."
            )
            generator.create_specification_by_llm()
            return

    

        if self.config.auto_annotation:
            generator.create_annotated_c_file()

        else:
            precondition = self.precond_manager.Require[func.name]
            annotation = f'''
            /*@
            Require {precondition}
            Ensure Results(__return)
            */
            '''
            generator.create_custom_annotated_c_file(annotation)

        loop_pattern = r'\b(for|while)\s*\((.*?)\)\s*{'
        matches = list(re.finditer(loop_pattern, func.code))

        if matches:
            self.logger.info(f"\nGENERATE LOOP INVARIANT FOR {func.name}")
            self.logger.info('='* 50+'\n')
            inv_generator = InvGenerator(self.config,func,self.logger,self.llm_config,generator)
            self.first_pass = inv_generator.run_pass()

        generator.create_looped_c_file()


    def _generate_annotations(self, func: FunctionInfo):
        """Generate function annotations and postconditions"""
        self.logger.info(f'Starting to generate annotation code for {func.name}')

     
        generator = SpecGenerator(
                func,
                self.function_info_list,
                self.global_type_info_dict,
                self.config,
                self.logger,
                self.llm_config,
                self.precond_manager
        )
        
        generator.create_generated_c_file()

        if self._is_recursive_function(func):
            self.logger.info(
                f"Recursive function {func.name}: skip automatic annotation/symbolic execution/translation and generate ACSL directly by LLM."
            )
            self.logger.info(f"\nGENERATE FUNCTION SPECIFICATION FOR {func.name}")
            self.logger.info('='* 50+'\n')
            generator.create_specification_by_llm()
            return



        if self.config.auto_annotation:
            generator.create_annotated_c_file()
        else:
            precondition = self.precond_manager.Require[func.name]
            annotation = f'''
            /*@
            Require {precondition}
            Ensure Results(__return)
            */
            '''
            generator.create_custom_annotated_c_file(annotation)

        loop_pattern = r'\b(for|while)\s*\((.*?)\)\s*{'
        matches = list(re.finditer(loop_pattern, func.code))

        if matches:
            self.logger.info(f"\nGENERATE LOOP INVARIANT FOR {func.name}")
            self.logger.info('='* 50+'\n')
            inv_generator = InvGenerator(self.config,func,self.logger,self.llm_config,generator)
            inv_generator.run()

        if self._should_skip_contract_generation(func):
            self.logger.info(
                f"Skip contract generation for {func.name}: no explicit verification target and only plain int inputs."
            )
            generator.create_looped_c_file()
            return

        # Postcondition generation (enable as needed)
        self.logger.info(f"\nGENERATE FUNCTION SPECIFICATION FOR {func.name}")
        self.logger.info('='* 50+'\n')
        
        post_cond = create_post(
            func.name,
            self.config.annotated_loop_c_file_path,
            self.conds,
            goal_dir=self.config.goal_run_path,
        )


        if post_cond != 'SymExec Failed':
            postcond_list = post_cond
            func.annotation = update_annotation(func.annotation, postcond_list)
            self.logger.info(f'Starting to generate complete annotation code for {func.name}')

            generator.create_final_c_file()

            self.logger.info(f'Starting to generate ACSL specification for {func.name}')
            # generator.create_specification()

            if self.config.auto_post:
                generator.create_specification()
            else:
                generator.create_specification_by_llm()
        
        else:
            self.logger.info(f'Starting to generate ACSL specification for {func.name}')
            generator.create_specification_by_llm()
            

    

    def run_analysis(self):
        """Execute main generation workflow"""
        # Start overall timing
        self.start_time = time.time()
        self.logger.info(f"\n🚀 Starting generation of function: {self.config.function_name}")
        
        # Initialize entry function
        self.logger.info("\nFUNCTION INITIALIZATION")
        self.logger.info('='* 50+'\n')
        
        main_func = self._initialize_function(self.config.function_name)
        self.top_function_info = main_func

        self.precond_manager = PreconditionsManager(main_func.file_path,self.preconditions)
      

        if main_func.name in self.precond_manager.requires:
            main_func.require = self.precond_manager.requires[main_func.name]

        self.function_info_list.append(main_func)
        self.pending_functions = [main_func.name, *main_func.callee_set]
        self.logger.info(f"Initial pending functions: {self.pending_functions}")

        # Process function queue
        while self.pending_functions:
            current_func = self.pending_functions.pop()
            
            # Check if already initialized
            existing_func = next(
                (f for f in self.function_info_list if f.name == current_func),
                None
            )

            if existing_func:
                self._handle_existing_function(existing_func)

            else:
               
                self._process_new_function(current_func)

        # Output results and cleanup

        self._finalize()

        if not self.config.only_loop:
            # self._verify()
            self._verify_pass()

        if not self.config.only_loop and self.config.generlization:
            self.__generalization()
            
        # End overall timing and output statistics
        self.end_time = time.time()
        self._log_overall_timing()
        self._log_token_stats()
        self._write_run_summary()

    def _handle_existing_function(self, func: FunctionInfo):
        """Handle already initialized functions"""

        self.logger.info(f"\nGENERATE ANNOTATION FOR {func.name}")
        self.logger.info('='* 50+'\n')

        self.logger.info(f'Function {func.name} has been initialized')
        if not func.annotation:
            if self.config.only_loop:
                self.__generate_loop_invariant(func)
            else:   
                self._generate_annotations(func)
            
        self.function_info_list.append(func)

    def __generalization(self):
        self.logger.info(f"\nGENERLIZATION FOR {self.config.function_name}")
        self.logger.info('='* 50+'\n')
        main_func = next(
            f for f in self.function_info_list 
            if f.name == self.config.function_name
        )
        convertor = SpecificationConvertor(main_func, self.llm_config)
        if convertor.z3_map:
         
            post2DSL = Post2DSL(main_func.specification,convertor.z3_map,self.config,self.logger)
            self.logger.info(f'\nMaximum non-redundant set for {self.config.function_name}:')
            self.logger.info(post2DSL.D)

    def _finalize(self):
        """Final processing and cleanup"""
        # Get main function result
        main_func = next(
            f for f in self.function_info_list 
            if f.name == self.config.function_name
        )
        if not self.config.only_loop:
            self.logger.info(f"\nSPECIFICATION FOR {self.config.function_name}")
            self.logger.info('='* 50+'\n')

            self.logger.info(f'\nQCP Specification for function {self.config.function_name}:\n{main_func.annotation}')
            if main_func.specification:
                self.logger.info(f'\nACSL Specification for function {self.config.function_name}:\n{main_func.specification}')
        
        free_all_tu(self.tu_dict)


    def _verify_pass(self):

        self.logger.info(f"\nVERIFICATION FOR {self.config.function_name}")
        self.logger.info('='* 50+'\n')

        # Used to record results for each round
        results = []

        # Record the earliest round that satisfies (initialized to None)
        first_valid_round = None
        first_syntax_round = None
        first_satisfy_round = None
        last_failure_reason = "not_run"

        for t in range(self.pass_count):
            self.logger.info(f'TRY TIME: {t}')

            verifier = SpecVerifier(self.config,self.logger)
            verifier.run(self.config.function_name)   # Pass complete path
            status_summary = verifier.status_summary

            post_result = verifier.post_result 
            assert_result = verifier.assert_result 
            loop_result = verifier.loop_result
            instance_result = verifier.instance_result
            syntax_error = verifier.syntax_error 

                        # Determine verification result
            valid = status_summary.get("validity_status") == "pass"
            syntax = status_summary.get("syntax_status") == "pass"
            satisfy = status_summary.get("satisfy_status") == "pass"

                   # Save this round result
            results.append({
                    "round": t + 1,   # Start counting from 1
                    "valid": valid,
                    "syntax": syntax,
                    "satisfy": satisfy
                })

                # If it's the first time satisfied, record it
            
            if syntax and first_syntax_round is None:
                first_syntax_round = t + 1
            if syntax and valid and first_valid_round is None:
                first_valid_round = t + 1
            if syntax and valid and satisfy and first_satisfy_round is None:
                first_satisfy_round = t + 1
            last_failure_reason = status_summary.get("failure_reason", "unknown")


            if not syntax or not valid or not satisfy:
                main_func = next(
                f for f in self.function_info_list 
                if f.name == self.config.function_name
            )
                generator = SpecGenerator(
                    main_func,
                    self.function_info_list,
                    self.global_type_info_dict,
                    self.config,
                    self.logger,
                    self.llm_config,
                    self.precond_manager
                )
                generator.create_specification_by_llm()
            else:
                # Print final specification
                main_func = next(
                    f for f in self.function_info_list 
                    if f.name == self.config.function_name
                )
                self.logger.info(f"\n🎯 FINAL SPECIFICATION FOR {self.config.function_name}")
                self.logger.info('='* 50)
                
                # Print output path content
                output_file_path = os.path.join(self.config.output_path, self.config.function_name + '.c')
                self.logger.info(f"Output path: {output_file_path}")
                
                # Print the content of the output file
                if os.path.exists(output_file_path):
                    try:
                        with open(output_file_path, 'r', encoding='utf-8') as f:
                            file_content = f.read()
                        self.logger.info(f"Output file content:\n{file_content}")
                    except Exception as e:
                        self.logger.info(f"Error reading output file: {e}")
                else:
                    self.logger.info(f"Output file does not exist: {output_file_path}")
                
                
                self.logger.info('='* 50)
                break


        self.logger.info("first_pass:")
        syntax_status = "pass" if first_syntax_round is not None else "fail"
        validity_status = "pass" if first_valid_round is not None else "fail"
        satisfy_status = "pass" if first_satisfy_round is not None else "fail"
        self.logger.info(
            f"syntax_round={first_syntax_round or 0}, valid_round={first_valid_round or 0}, satisfy_round={first_satisfy_round or 0}"
        )
        self.logger.info(
            f"syntax_status={syntax_status}, validity_status={validity_status}, satisfy_status={satisfy_status}"
        )
        self.logger.info(f"failure_reason={last_failure_reason}")
        self.first_pass ={
            "syntax": first_syntax_round or 0,
            "valid": first_valid_round or 0,
            "satisfy": first_satisfy_round or 0,
            "syntax_status": syntax_status,
            "validity_status": validity_status,
            "satisfy_status": satisfy_status,
            "failure_reason": last_failure_reason,
            "mode": "full_spec",
        }

        


    def _verify(self):
        self.logger.info(f"\nVERIFICATION FOR {self.config.function_name}")
        self.logger.info('='* 50+'\n')

        verifier = SpecVerifier(self.config,self.logger)
        verifier.run(self.config.function_name)   # Pass complete path

# Usage example
if __name__ == '__main__':
    # Parse command line arguments
    args = parse_arguments()
    
    # Run analysis from configuration file
    run_from_config(
        config_path=args.config,
        function_name=args.function,
        root_dir=args.root_dir
    )
