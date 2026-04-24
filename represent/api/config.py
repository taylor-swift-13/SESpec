from __future__ import annotations

import os
from dataclasses import dataclass
from functools import lru_cache
from pathlib import Path
from typing import Any

import yaml


ROOT = Path(__file__).resolve().parents[2]
DEFAULT_CONFIG = ROOT / "represent" / "config" / "models.yaml"
EXAMPLE_CONFIG = ROOT / "represent" / "config" / "models.example.yaml"


@dataclass(frozen=True)
class Settings:
    raw: dict[str, Any]

    @property
    def env_name(self) -> str:
        return self.raw.get("env_name", "SpecAutoGen")

    @property
    def base_url(self) -> str:
        return self.raw["api"]["base_url"]

    @property
    def api_key(self) -> str:
        api = self.raw["api"]
        if api.get("api_key"):
            return api["api_key"]
        env_name = api.get("api_key_env", "OPENAI_API_KEY")
        value = os.environ.get(env_name, "")
        if not value:
            raise RuntimeError(
                f"Missing API key. Set {env_name} or place api.api_key in {config_path()}."
            )
        return value

    @property
    def model_list(self) -> list[str]:
        return list(self.raw.get("models", []))

    @property
    def temperature(self) -> float:
        return float(self.raw["api"].get("temperature", 0.7))

    @property
    def top_p(self) -> float:
        return float(self.raw["api"].get("top_p", 0.7))

    @property
    def max_tokens(self) -> int:
        return int(self.raw["api"].get("max_tokens", 2048))

    @property
    def paths(self) -> dict[str, str]:
        return dict(self.raw.get("paths", {}))

    @property
    def tools(self) -> dict[str, Any]:
        return dict(self.raw.get("tools", {}))


def config_path() -> Path:
    path = os.environ.get("REPRESENT_CONFIG")
    if path:
        return Path(path).expanduser().resolve()
    if DEFAULT_CONFIG.exists():
        return DEFAULT_CONFIG
    return EXAMPLE_CONFIG


@lru_cache(maxsize=1)
def get_settings() -> Settings:
    with config_path().open("r", encoding="utf-8") as handle:
        return Settings(yaml.safe_load(handle))

