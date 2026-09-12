import unittest

from judge_prompts import PROMPTS
from judge_routing import inspect_spec, route_pair


LOOP = r'int f(int n) { int i=0; /*@ loop invariant 0 <= i <= n; */ while(i<n) ++i; return i; }'


class RoutingTests(unittest.TestCase):
    def test_both_pure_invariants(self):
        self.assertEqual(route_pair(LOOP, LOOP, 'c', 'f', 'f')['comparison_basis'], 'loop_invariants')

    def test_contract_on_either_side_wins(self):
        contract = '/*@ requires n >= 0; */\n' + LOOP
        for a, b in [(contract, LOOP), (LOOP, contract)]:
            self.assertEqual(route_pair(a, b, 'c', 'f', 'f')['comparison_basis'], 'contract')

    def test_explicit_true_uses_invariants(self):
        contract = '/*@ requires ((\\true)); ensures \\true; assigns \\nothing; */\n' + LOOP
        self.assertEqual(route_pair(contract, LOOP, 'c', 'f', 'f')['comparison_basis'], 'loop_invariants')

    def test_prototype_contract_is_preserved(self):
        source = '/*@ ensures \\result == n; */ int f(int n);\n' + LOOP
        self.assertEqual(route_pair(source, LOOP, 'c', 'f', 'f')['comparison_basis'], 'contract')

    def test_other_function_contract_is_ignored(self):
        source = '/*@ requires n>0; */ int other(int n){return n;}\n' + LOOP
        self.assertEqual(route_pair(source, LOOP, 'c', 'f', 'f')['comparison_basis'], 'loop_invariants')

    def test_java_line_ensures_is_detected(self):
        a = 'class T {\n //@ ensures \\result == x*1.8+32;\n public double f(double x){return x*1.8+32;} }'
        b = 'double g(double x){return x*1.8+32;}'
        route = route_pair(a, b, 'java', 'f', 'g')
        self.assertEqual(route['A']['nontrivial_contract_clause_count'], 1)
        self.assertEqual(route['comparison_basis'], 'contract')

    def test_overloaded_java_uses_unique_arity(self):
        a = 'class T { /*@ ensures \\result==x; */ int f(int x){return x;}\n int f(int x,int y){ /*@ loop_invariant x>=0; */ while(x>0)--x;return x;} }'
        b = 'int g(int x,int y){/*@ loop invariant x>=0; */while(x>0)--x;return x;}'
        route = route_pair(a, b, 'java', 'f', 'g')
        self.assertEqual(route['A']['parameter_count'], 2)
        self.assertEqual(route['comparison_basis'], 'loop_invariants')

    def test_empty_specs_and_string_literals(self):
        a = 'int f(void){const char *s="/*@ loop invariant x>0; */";return 1;}'
        self.assertEqual(inspect_spec(a, 'c', 'f')['invariant_count'], 0)
        self.assertEqual(route_pair(a, a, 'c', 'f', 'f')['comparison_basis'], 'contract')

    def test_only_true_invariants_are_empty(self):
        source = r'int f(void){/*@ loop invariant \true; */ while(0){} return 0;}'
        self.assertEqual(route_pair(source, source, 'c', 'f', 'f')['comparison_basis'], 'contract')

    def test_prompts_do_not_ask_model_to_route(self):
        for system, template in PROMPTS.values():
            prompt = template.format(lang_a='c', spec_a=LOOP, spec_b=LOOP)
            self.assertNotIn('comparison_basis', prompt)
            for name in ['AutoSpec', 'SpecGen', 'SESpec']:
                self.assertNotIn(name, system + prompt)


if __name__ == '__main__':
    unittest.main()
