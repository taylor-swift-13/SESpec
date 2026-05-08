import os
from dataclasses import dataclass

@dataclass
class MainConfig:
    """Global configuration class for main process

    All run artifacts (1_output / 2_output / 3_output / output / loop) are
    materialized inside a per-run ``workspace_root`` under ``log_dir``; the
    legacy top-level ``*_dir`` defaults were unused and have been removed.
    """
    root_dir: str = None  # Original input
    input_dir: str = 'input' # Unified format input, can manually inject ACSL format preconditions and verification targets
    log_dir: str = 'log'

    
    function_name: str = None

    input_path:str =None
    annotated_c_file_path: str = None
    annotated_loop_c_file_path: str = None
    generated_loop_c_file_path: str = None
    output_path:str = None

    debug:bool = True
    generlization:bool = False
    recursive_loop:bool = False
    only_loop:bool = False  # Set automatically by FunctionProcessor._auto_set_only_loop based on function signature + side-effect scan; do not configure manually.

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
    api_model:str = "claude-3-7-sonnet-20250219" # API model name, e.g., "gpt-4o"
    api_key:str = os.environ.get("OPENAI_API_KEY", "")
    base_url:str = "https://yunwu.ai/v1"
    api_temperature = 0.7 # Temperature parameter for API calls
    api_top_p=0.7
    think_mode_enabled = False
    









   