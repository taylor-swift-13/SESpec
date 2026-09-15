"""Resolve paths embedded in pre-reorganization paper experiment manifests."""

from pathlib import Path


DATA_ROOT = Path(__file__).resolve().parents[1] / "RESULTS" / "paper_data"
FORMER_FINAL_ROOT = DATA_ROOT.with_name("paper_data_final")

LEGACY_LOCATIONS = {
    "AutoSpec": "rq5_validity/runs/autospec",
    "LLM-C": "rq5_validity/runs/llm_c",
    "LLM-Java": "rq5_validity/runs/llm_java",
    "SESpec": "rq5_validity/runs/sespec",
    "SESpec_no_refine": "rq5_validity/runs/sespec_no_refine",
    "SESpec_trivial_refine": "rq5_validity/runs/sespec_trivial_refine",
    "SpecGen": "rq5_validity/runs/specgen",
    "c_inputs": "benchmark/c_inputs",
    "java_inputs": "benchmark/java_inputs",
}


def resolve_path(value: str | Path) -> Path:
    """Return the current location while keeping archived manifest text intact."""
    path = Path(value)
    if path.exists():
        return path
    absolute = path if path.is_absolute() else DATA_ROOT.parents[1] / path
    try:
        relative = absolute.relative_to(DATA_ROOT)
    except ValueError:
        try:
            relative = absolute.relative_to(FORMER_FINAL_ROOT)
        except ValueError:
            return path
    if not relative.parts or relative.parts[0] not in LEGACY_LOCATIONS:
        return path
    return DATA_ROOT / LEGACY_LOCATIONS[relative.parts[0]] / Path(*relative.parts[1:])
