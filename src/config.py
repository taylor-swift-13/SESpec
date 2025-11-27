from dataclasses import dataclass

@dataclass
class MainConfig:
    """Global configuration class for main process
    
    Attributes:
        root_dir (str): Project root directory path
        input_dir (str): Preprocessed input directory (default 'input')
        annotated_c_dir (str): Intermediate directory with VST format annotations (default '1_output')
        annotated_loop_dir (str): Complete loop annotation directory (default '2_output')
        generated_loop_dir (str): ACSL format invariant generation directory (default '3_output')
        output_dir (str): Final output directory (default 'output')
    """
    """Configuration parameter class"""
    root_dir: str = None  # Original input
    input_dir: str = 'input' # Unified format input, can manually inject ACSL format preconditions and verification targets
    annotated_c_dir: str = '1_output' # VST format annotated preconditions, can manually inject VST format preconditions and verification targets
    annotated_loop_dir:str = '2_output' # VST format complete annotations
    generated_loop_dir :str = '3_output' # ACSL format annotated preconditions, verification targets, invariants
    output_dir:str = 'output' # ACSL format complete annotations
    log_dir:str = 'log'

    
    function_name: str = None

    input_path:str =None
    annotated_c_file_path: str = None
    annotated_loop_c_file_path: str = None
    generated_loop_c_file_path: str = None
    output_path:str = None

    debug:bool = True
    generlization:bool = False
    only_loop:bool = True 
    recursive_loop:bool = False

    # T: Use input_dir as the only input
    # F: Use input_dir and preconditions as input
    auto_annotation:bool = True

    # Ablation study parameters
    refine_count:int = 3
    pass_count:int = 5
    think:bool = True
    template:bool = True
    auto_post:bool = True # Whether to automatically generate postconditions

    use_db:bool = True
    db_path:str = 'VectorDB/Jsons/init.json'

    collect:bool = False

@dataclass
class LLMConfig:
    # API model configuration
    use_api_model = True # Control whether to use API model or local Transformers model
    api_model:str = "gpt-4o" # API model name, e.g., "gpt-4o"
    api_key:str = "sk-afVplv2oRlR8_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"
    base_url:str = "https://yunwu.ai/v1"
    api_temperature = 0.7 # Temperature parameter for API calls
    api_top_p=0.7
    think_mode_enabled = False
    









   