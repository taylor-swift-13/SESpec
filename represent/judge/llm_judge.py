from __future__ import annotations

import json
import re
from pathlib import Path
from typing import Any

from represent.api.client import chat_completion


JUDGE_SYSTEM_PROMPT = """You are a formal-methods evaluator.
You judge whether a candidate specification completely captures the semantics of a program.
Focus on semantic completeness, not surface syntax style.
Be strict. If important behaviors, preconditions, postconditions, edge cases, mutation effects, or return-value relations are missing, the spec is not complete.
Also detect cheating specifications. A cheating spec must receive score 0.
Examples of cheating include:
- encoding the implementation logic or branch-by-branch algorithm directly into the spec instead of giving a proper behavioral contract
- adding over-strong preconditions that exclude difficult or normal inputs just to make verification pass
- leaking the expected result as an assumption, axiom, ghost shortcut, or tautological postcondition
- writing a vacuous spec that is syntactically valid but semantically empty
- using helper predicates, logic functions, or assumptions whose only purpose is to hide missing semantics
Return score 1 only when the spec is semantically complete enough to count as a full description of the program.
Otherwise return score 0.
Return only valid JSON.
"""


def _extract_json(text: str) -> dict[str, Any]:
    text = text.strip()
    if text.startswith("{") and text.endswith("}"):
        return json.loads(text)
    match = re.search(r"\{.*\}", text, re.DOTALL)
    if not match:
        raise ValueError(f"Judge response is not JSON: {text[:300]}")
    return json.loads(match.group(0))


def _read_text(path: str | Path) -> str:
    return Path(path).read_text(encoding="utf-8", errors="ignore")


def build_judge_prompt(
    *,
    language: str,
    original_program: str,
    candidate_program_with_spec: str,
) -> str:
    return f"""Evaluate whether the specification in the candidate program completely describes the semantics of the original program.

Language: {language}

Original program:
```{language}
{original_program}
```

Candidate program with specification:
```{language}
{candidate_program_with_spec}
```

Judge the candidate specification only, not the implementation text that may still be present.
You must explicitly check whether the spec is cheating.

A spec is cheating if it avoids the real contract-writing task by, for example:
- excluding normal inputs with suspiciously strong preconditions
- smuggling in the answer through assumptions, axioms, ghost artifacts, or circular claims
- restating implementation steps instead of specifying observable behavior
- being technically parseable but behaviorally vacuous

If the spec is cheating, incomplete, overconstrained, underconstrained, or semantically wrong, score must be 0.

Output JSON with exactly these keys:
- score: integer, must be 0 or 1
- semantic_complete: boolean
- cheating: boolean
- cheating_signals: array of short strings
- missing_semantics: array of short strings
- wrong_or_overconstrained_claims: array of short strings
- summary: short string

Scoring rule:
- score = 1 only if the spec captures the full intended semantics with no material gaps, no wrong claims, and no cheating
- score = 0 if it is incomplete, partially correct, underspecified, overspecified, or semantically wrong

Return JSON only.
"""


def judge_spec_completeness(
    *,
    model: str,
    language: str,
    original_program_path: str | Path,
    candidate_program_path: str | Path,
    usage_log: str | Path | None = None,
) -> dict[str, Any]:
    original_program = _read_text(original_program_path)
    candidate_program = _read_text(candidate_program_path)
    prompt = build_judge_prompt(
        language=language,
        original_program=original_program,
        candidate_program_with_spec=candidate_program,
    )
    response = chat_completion(
        messages=[
            {"role": "system", "content": JUDGE_SYSTEM_PROMPT},
            {"role": "user", "content": prompt},
        ],
        model=model,
        temperature=0.0,
        top_p=1.0,
        usage_log=usage_log,
    )
    payload = _extract_json(response["content"])
    raw_score = payload.get("score", 0)
    payload["score"] = 1 if str(raw_score).strip() in {"1", "true", "True"} else 0
    payload["cheating_signals"] = list(payload.get("cheating_signals", []))
    payload["missing_semantics"] = list(payload.get("missing_semantics", []))
    payload["wrong_or_overconstrained_claims"] = list(payload.get("wrong_or_overconstrained_claims", []))
    payload["semantic_complete"] = bool(payload["score"])
    payload["cheating"] = bool(payload.get("cheating", False))
    if payload["cheating"]:
        payload["score"] = 0
        payload["semantic_complete"] = False
    payload["judge_model"] = model
    payload["language"] = language
    payload["original_program_path"] = str(original_program_path)
    payload["candidate_program_path"] = str(candidate_program_path)
    payload["token_usage"] = response["usage"]
    return payload
