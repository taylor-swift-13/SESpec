int NotCommonMultiple(int a, int b, int m);

/*@ 
  requires a != 0;
  requires b != 0;
  assigns \nothing;
  ensures 0 <= \result <= 1;
  ensures (\result == 0) <==> (m % a == 0 && m % b == 0);

  behavior both_divide:
    assumes m % a == 0 && m % b == 0;
    ensures \result == 0;

  behavior at_least_one_not_dividing:
    assumes m % a != 0 || m % b != 0;
    ensures \result == 1;

  complete behaviors both_divide, at_least_one_not_dividing;
  disjoint behaviors both_divide, at_least_one_not_dividing;
*/
int NotCommonMultiple(int a, int b, int m) {

        return m % a != 0 || m % b != 0;
}
