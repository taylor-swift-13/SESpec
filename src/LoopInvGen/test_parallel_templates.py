import json
import logging
import os
import tempfile
import threading
import unittest
from types import SimpleNamespace

from config_loader import ConfigLoader
from LoopInvGen.inv_gen import InvGenerator


class _BarrierChatbot:
    def __init__(self, barrier, created):
        self.barrier = barrier
        self.created = created
        self.created.append(self)

    def chat(self, prompt):
        self.barrier.wait(timeout=2)
        return f"response:{prompt}"


class ParallelTemplateTests(unittest.TestCase):
    def generator(self, *, source="", goal_available=None):
        generator = object.__new__(InvGenerator)
        generator.config = SimpleNamespace(goal_available=goal_available)
        generator.info = SimpleNamespace(code=source)
        generator.llm_config = SimpleNamespace()
        generator.logger = logging.getLogger("parallel-template-test")
        return generator

    def test_parallel_generation_is_concurrent_and_ordered(self):
        generator = self.generator()
        barrier = threading.Barrier(3)
        created = []
        generator._parallel_chatbot_factory = lambda: _BarrierChatbot(
            barrier, created
        )

        results = generator._parallel_generate_templates([
            ("SE", "slow-first"),
            ("SE+goal", "second"),
            ("Simple", "third"),
        ])

        self.assertEqual(3, len(created))
        self.assertEqual([
            ("SE", "response:slow-first"),
            ("SE+goal", "response:second"),
            ("Simple", "response:third"),
        ], results)

    def test_goal_availability_uses_only_visible_source(self):
        self.assertFalse(self.generator(source="while (x) { x--; }")._goal_is_available())
        self.assertTrue(self.generator(
            source="while (x) { x--; } /*@ assert x == 0; */"
        )._goal_is_available())
        self.assertFalse(self.generator(
            source="/*@ assert secret; */", goal_available=False
        )._goal_is_available())

    def test_parallel_merge_unions_and_deduplicates_loop_clauses(self):
        candidates = [
            """void f(void) {
/*@
  loop invariant x >= 0;
  loop assigns x;
*/
while (x) { x--; }
}
""",
            """void f(void) {
/*@
  loop invariant x >= 0;
  loop invariant x <= 10;
  loop assigns x;
*/
while (x) { x--; }
}
""",
            """void f(void) {
/*@
  loop invariant \\forall integer k; 0 <= k < x ==> k < 10;
  loop invariant PLACE_HOLDER_VERFICATION_GOAL;
*/
while (x) { x--; }
}
""",
        ]

        merged = InvGenerator._merge_parallel_annotations(
            candidates, candidates[0]
        )

        self.assertEqual(1, merged.count("loop invariant x >= 0;"))
        self.assertIn("loop invariant x <= 10;", merged)
        self.assertIn("loop invariant \\forall integer k;", merged)
        self.assertEqual(1, merged.count("loop assigns x;"))
        self.assertNotIn("PLACE_HOLDER_VERFICATION_GOAL", merged)

    def test_parallel_merge_preserves_fallback_program_structure(self):
        fallback = """/*@
PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
*/
void f(void) {
/*@
  loop invariant PLACE_HOLDER_x;
*/
while (x) { x--; }
}
"""
        model_response = """/*@ logic integer next(integer x) = x + 1; */
void f(void) {
/*@
  loop invariant x >= 0;
  loop invariant next(x) > x;
*/
while (x) { x += 99; }
}
"""

        merged = InvGenerator._merge_parallel_annotations(
            [model_response], fallback
        )

        self.assertIn("loop invariant x >= 0;", merged)
        self.assertIn("logic integer next(integer x)", merged)
        self.assertIn("while (x) { x--; }", merged)
        self.assertNotIn("x += 99", merged)
        self.assertNotIn("PLACE_HOLDER_", merged)

    def test_config_loader_reads_explicit_goal_availability(self):
        handle, path = tempfile.mkstemp(suffix=".json")
        try:
            with os.fdopen(handle, "w", encoding="utf-8") as stream:
                json.dump({"main": {"goal_available": False}}, stream)
            self.assertFalse(
                ConfigLoader(path).get_main_config().goal_available
            )
        finally:
            os.unlink(path)


if __name__ == "__main__":
    unittest.main()
