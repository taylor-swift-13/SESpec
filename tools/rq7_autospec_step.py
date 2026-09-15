#!/usr/bin/env python3
"""Run one archived AutoSpec step with an environment-supplied API endpoint."""

import os
from pathlib import Path
import sys


AUTOSPEC_ROOT = Path(os.environ["RQ7_AUTOSPEC_ROOT"])
os.chdir(AUTOSPEC_ROOT)
sys.path.insert(0, str(AUTOSPEC_ROOT))

import conf.jsoninfo as config

original_load = config.load_json_config
proxy_names = ("HTTP_PROXY", "HTTPS_PROXY", "http_proxy", "https_proxy")
proxy_env = {name: os.environ.get(name) for name in proxy_names}


def load_with_endpoint(selection):
    settings = original_load(selection)
    os.environ["OPENAI_API_KEY"] = os.environ["RQ7_API_KEY"]
    os.environ["API_URL_BASE"] = os.environ["RQ7_BASE_URL"]
    for name, value in proxy_env.items():
        if value is None:
            os.environ.pop(name, None)
        else:
            os.environ[name] = value
    return settings


config.load_json_config = load_with_endpoint

import step

step.main(sys.argv[1:])
