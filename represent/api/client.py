from __future__ import annotations

import json
import os
from pathlib import Path
from typing import Any

from openai import OpenAI

from .config import get_settings


def project_env(extra: dict[str, str] | None = None) -> dict[str, str]:
    settings = get_settings()
    env = os.environ.copy()
    env["OPENAI_API_KEY"] = settings.api_key
    env["API_URL_BASE"] = settings.base_url
    env["OPENAI_BASE_URL"] = settings.base_url
    if extra:
        env.update(extra)
    return env


def chat_completion(
    *,
    messages: list[dict[str, str]],
    model: str,
    temperature: float | None = None,
    top_p: float | None = None,
    max_tokens: int | None = None,
    usage_log: str | Path | None = None,
) -> dict[str, Any]:
    settings = get_settings()
    client = OpenAI(api_key=settings.api_key, base_url=settings.base_url)
    response = client.chat.completions.create(
        model=model,
        messages=messages,
        temperature=settings.temperature if temperature is None else temperature,
        top_p=settings.top_p if top_p is None else top_p,
        max_tokens=settings.max_tokens if max_tokens is None else max_tokens,
    )
    payload = {
        "content": response.choices[0].message.content or "",
        "usage": {
            "prompt_tokens": getattr(response.usage, "prompt_tokens", 0) or 0,
            "completion_tokens": getattr(response.usage, "completion_tokens", 0) or 0,
            "total_tokens": getattr(response.usage, "total_tokens", 0) or 0,
        },
    }
    if usage_log:
        usage_path = Path(usage_log)
        usage_path.parent.mkdir(parents=True, exist_ok=True)
        with usage_path.open("a", encoding="utf-8") as handle:
            handle.write(json.dumps({"model": model, **payload["usage"]}) + "\n")
    return payload

