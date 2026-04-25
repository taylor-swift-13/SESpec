import json
import yaml
import os
from typing import Dict, Any, Tuple
from config import MainConfig, LLMConfig


class ConfigLoader:
    """Configuration file loader supporting JSON and YAML formats"""
    
    def __init__(self, config_path: str):
        """
        Initialize configuration loader
        
        Args:
            config_path (str): Configuration file path
        """
        self.config_path = config_path
        self.config_data = self._load_config()
    
    def _load_config(self) -> Dict[str, Any]:
        """Load configuration file"""
        if not os.path.exists(self.config_path):
            raise FileNotFoundError(f"Configuration file does not exist: {self.config_path}")
        
        with open(self.config_path, 'r', encoding='utf-8') as f:
            if self.config_path.endswith('.json'):
                return json.load(f)
            elif self.config_path.endswith(('.yml', '.yaml')):
                return yaml.safe_load(f)
            else:
                raise ValueError(f"Unsupported configuration file format: {self.config_path}")
    
    def get_main_config(self) -> MainConfig:
        """Get code analyzer configuration"""
        main_config = self.config_data.get('main', {})
        
        # Create MainConfig instance
        config = MainConfig()
        
        # Set basic parameters
        config.root_dir = main_config.get('root_dir')
        config.input_dir = main_config.get('input_dir', config.input_dir)
        config.function_name = main_config.get('function_name')
        config.run_id = main_config.get('run_id', config.run_id)
        config.debug = main_config.get('debug', config.debug)
        config.only_loop = main_config.get('only_loop', config.only_loop)
        config.recursive_loop = main_config.get('recursive_loop', config.recursive_loop)
        config.auto_annotation = main_config.get('auto_annotation', config.auto_annotation)
        config.refine_count = main_config.get('refine_count', config.refine_count)
        config.pass_count = main_config.get('pass_count', config.pass_count)
        config.think = main_config.get('think', config.think)
        config.template = main_config.get('template', config.template)
        config.auto_post = main_config.get('auto_post', config.auto_post)
        config.use_symbolic_execution = main_config.get('use_symbolic_execution', config.use_symbolic_execution)
        
        return config
    
    def get_preconditions(self) -> Dict[str, str]:
        """Get preconditions configuration"""
        return self.config_data.get('preconditions', {})
    
    def get_model_name(self) -> str:
        """Get model name"""
        llm_config = self.config_data.get('llm', {})
        return llm_config.get('api_model', 'gpt-4o')

    def get_llm_config(self) -> LLMConfig:
        """Get full llm configuration"""
        llm_section = self.config_data.get('llm', {})
        config = LLMConfig()
        config.api_model = llm_section.get('api_model', config.api_model)
        config.base_url = llm_section.get('base_url', config.base_url)
        config.api_key = llm_section.get('api_key', os.environ.get('OPENAI_API_KEY', config.api_key))
        config.api_temperature = llm_section.get('api_temperature', config.api_temperature)
        config.api_top_p = llm_section.get('api_top_p', config.api_top_p)
        config.use_api_model = llm_section.get('use_api_model', config.use_api_model)
        config.think_mode_enabled = llm_section.get('think_mode_enabled', config.think_mode_enabled)
        return config


def load_config_from_file(config_path: str) -> Tuple[MainConfig, Dict[str, str], LLMConfig]:
    """
    Load all configurations from configuration file
    
    Args:
        config_path (str): Configuration file path
        
    Returns:
        tuple: (MainConfig, preconditions, llm_config)
    """
    loader = ConfigLoader(config_path)
    
    main_config = loader.get_main_config()
    preconditions = loader.get_preconditions()
    llm_config = loader.get_llm_config()
    
    return main_config, preconditions, llm_config
