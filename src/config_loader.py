import json
import yaml
import os
from typing import Dict, Any, Union,Tuple
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
        config.function_name = main_config.get('function_name')
        config.debug = main_config.get('debug', config.debug)
        config.only_loop = main_config.get('only_loop', config.only_loop)
        config.recursive_loop = main_config.get('recursive_loop', config.recursive_loop)
        config.auto_annotation = main_config.get('auto_annotation', config.auto_annotation)
        config.refine_count = main_config.get('refine_count', config.refine_count)
        config.pass_count = main_config.get('pass_count', config.pass_count)
        config.think = main_config.get('think', config.think)
        config.template = main_config.get('template', config.template)
        config.auto_post = main_config.get('auto_post', config.auto_post)
        config.use_db = main_config.get('use_db', config.use_db)
        config.collect = main_config.get('collect', config.collect)
        
        return config
    
    def get_preconditions(self) -> Dict[str, str]:
        """Get preconditions configuration"""
        return self.config_data.get('preconditions', {})
    
    def get_model_name(self) -> str:
        """Get model name"""
        llm_config = self.config_data.get('llm', {})
        return llm_config.get('api_model', 'gpt-4o')


def load_config_from_file(config_path: str) -> Tuple[MainConfig, LLMConfig, Dict[str, str], str]:
    """
    Load all configurations from configuration file
    
    Args:
        config_path (str): Configuration file path
        
    Returns:
        tuple: (MainConfig, preconditions, model_name)
    """
    loader = ConfigLoader(config_path)
    
    main_config = loader.get_main_config()
    preconditions = loader.get_preconditions()
    model_name = loader.get_model_name()
    
    return main_config, preconditions, model_name
