import re
import sys
import logging
import os 
import time
import argparse
from datetime import datetime

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
from vector_db_manager import get_vector_db
from pre_cond_manager import PreconditionsManager
from config_loader import load_config_from_file
from collector import Collector



def parse_arguments():
    """Parse command line arguments"""
    parser = argparse.ArgumentParser(description='ASGSE - Run with configuration file')
    parser.add_argument('--config', '-c', 
                       type=str, 
                       default='func_config.json',
                       help='Configuration file path (supports .json and .yaml formats)')
    parser.add_argument('--root-dir', '-r',
                       type=str,
                       help='Root directory (overrides config file setting)')
    parser.add_argument('--function', '-f',
                       type=str,
                       help='Function name (overrides config file setting)')
    parser.add_argument('--debug', '-d',
                       action='store_true',
                       help='Enable debug mode (overrides config file setting)')
    return parser.parse_args()


def run_from_config(config_path: str, function_name: str = None, root_dir: str = None, debug: bool = None):
    """
    Run analysis from configuration file
    
    Args:
        config_path (str): Configuration file path
        function_name (str, optional): Function name to analyze
        root_dir (str, optional): Project root directory
        debug (bool, optional): Whether to enable debug mode
        vector_db (bool, optional): Whether to enable vector database
    """
    try:
        # Load configuration file
        main_config,preconditions, model_name = load_config_from_file(config_path)
        
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
        print(f"🤖 Using model: {model_name}")
        
        # Create processor and run analysis
        processor = FunctionProcessor(main_config, preconditions, model_name)
        processor.run_analysis()
        
        print("✅ Generation completed!")
        
    except Exception as e:
        print(f"❌ Run failed: {e}")
        sys.exit(1)


def _setup_analysis_logger(function_name: str, log_dir: str,  debug: bool = False, to_console: bool = True) -> logging.Logger:
    """
    Configure and return an independent logger for specific function analysis tasks.
    Logs will be written to both file and console (if to_console is True).
    File logs include complete prefix, console logs do not include prefix.
    """
    # Ensure the log directory exists
    os.makedirs(log_dir, exist_ok=True)
    log_file_path = os.path.join(log_dir, f'{function_name}.log')

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
    
    def __init__(self, config: MainConfig,preconditions: Dict[str, Union[str, Tuple[str, Optional[str]]]] = None, model_name:str = 'gpt-4o') -> None:
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
        self.llm_config = LLMConfig(api_model=model_name)
        self.pending_functions: List[str] = []
        self.top_function_info = None
        self.first_pass = None
        self.preconditions = preconditions
        self.precond_manager = None
        self.pass_count = self.config.pass_count
        
        # Timing related attributes
        self.start_time = None
        self.end_time = None
        
        self.config.input_path = os.path.join(self.config.input_dir,self.config.root_dir)
        self.config.annotated_c_file_path= os.path.join(self.config.annotated_c_dir,self.config.root_dir)
        self.config.annotated_loop_c_file_path = os.path.join(self.config.annotated_loop_dir,self.config.root_dir)
        self.config.generated_loop_c_file_path =  os.path.join(self.config.generated_loop_dir,self.config.root_dir)
        self.config.output_path = os.path.join(self.config.output_dir,self.config.root_dir)
        self.config.log_dir = os.path.join(self.config.log_dir,f'{self.config.root_dir}/{self.llm_config.api_model}')

        # Create Log directory
        os.makedirs(self.config.log_dir, exist_ok=True)

        # Initialize dual-path Output
        self.logger = _setup_analysis_logger(
                function_name=self.config.function_name,
                log_dir=self.config.log_dir, 
                debug=self.config.debug, 
                to_console=True 
            )
        
        if self.config.use_db:
            self.vector_db = get_vector_db(self.config.db_path)
        else:
            self.vector_db = None

            
        
    def _log_overall_timing(self):
        """Log overall timing information"""
        if self.start_time and self.end_time:
            total_duration = self.end_time - self.start_time
            self.logger.info("="*50)
            self.logger.info("⏰ OVERALL EXECUTION TIME STATISTICS")
            self.logger.info(f"Total execution time: {total_duration:.2f} seconds ({total_duration/60:.2f} minutes)")
            self.logger.info("="*50)

        
        

    def _prepare_workspace(self):
        """Preprocess workspace directory (macro processing)"""
      
        process_all_c_files(self.config.root_dir,self.config.input_path)
        

    def _initialize_function(self, func_name: str) -> FunctionInfo:
        """Initialize single function information"""
       
        return function_info_init(
            self.tu_dict,
            self.config.input_path,
            func_name,
            self.file_cache,
            self.global_type_info_dict
        )
    
    


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
            inv_generator = InvGenerator(self.config,func,self.logger,self.vector_db,self.llm_config,generator)
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
            inv_generator = InvGenerator(self.config,func,self.logger,self.vector_db,self.llm_config,generator)
            inv_generator.run()

        # Postcondition generation (enable as needed)
        self.logger.info(f"\nGENERATE FUNCTION SPECIFICATION FOR {func.name}")
        self.logger.info('='* 50+'\n')
        
        post_cond = create_post(func.name,self.config.annotated_loop_c_file_path,self.conds)


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

        # Collect correct results
        if self.config.collect and self.first_pass['satisfy'] is not None:
            self._collect_results(main_func.file_path)
        

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
        convertor = SpecificationConvertor(main_func)
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

            self.logger.info(f'\nVST Specification for function {self.config.function_name}:\n{main_func.annotation}')
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

        for t in range(self.pass_count):
            self.logger.info(f'TRY TIME: {t}')

            verifier = SpecVerifier(self.config,self.logger)
            verifier.run(self.config.function_name)   # Pass complete path

            post_result = verifier.post_result 
            assert_result = verifier.assert_result 
            loop_result = verifier.loop_result
            instance_result = verifier.instance_result
            syntax_error = verifier.syntax_error 

                        # Determine verification result
            valid =  all(post_result) and all(loop_result) and all(instance_result)
            syntax = syntax_error ==''
            satisfy =  all(assert_result)

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
                self.config.output_path = os.path.join(self.config.output_path, self.config.function_name + '.c')
                self.logger.info(f"Output path: {self.config.output_path}")
                
                # Print the content of the output file
                if os.path.exists(self.config.output_path):
                    try:
                        with open(self.config.output_path, 'r', encoding='utf-8') as f:
                            file_content = f.read()
                        self.logger.info(f"Output file content:\n{file_content}")
                    except Exception as e:
                        self.logger.info(f"Error reading output file: {e}")
                else:
                    self.logger.info(f"Output file does not exist: {self.config.output_path}")
                
                
                self.logger.info('='* 50)
                break


        self.logger.info("first_pass:")
        self.logger.info(f"syntax={first_syntax_round}, valid={first_valid_round},satisfy={first_satisfy_round}")
        self.first_pass ={
            "syntax": first_syntax_round,
            "valid": first_valid_round,
            "satisfy": first_satisfy_round
        }

        


    def _verify(self):
        self.logger.info(f"\nVERIFICATION FOR {self.config.function_name}")
        self.logger.info('='* 50+'\n')

        verifier = SpecVerifier(self.config,self.logger)
        verifier.run(self.config.function_name)   # Pass complete path

    def _collect_results(self,input_file_path:str):
        self.logger.info("collecting results")
       
        output_file_path = self.config.output_path

        with open(input_file_path, 'r', encoding='utf-8') as f:
            input_code = f.read()
        with open(output_file_path, 'r', encoding='utf-8') as f:
            output_code = f.read()

        collector = Collector()

        collector.add_specification_to_file(input_code,output_code,'add.json')


      

# Usage example
if __name__ == '__main__':
    # Parse command line arguments
    args = parse_arguments()
    
    # Run analysis from configuration file
    run_from_config(
        config_path=args.config,
        function_name=args.function,
        root_dir=args.root_dir,
        debug=args.debug
    )

