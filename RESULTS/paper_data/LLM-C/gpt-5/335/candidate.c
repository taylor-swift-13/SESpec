/*@ 
  logic integer ldp(integer a, integer b) = 
    (b <= a) ? 1 : ((ldp(a, b - 1) * (b % 10)) % 10);

  lemma ldp_zero_if_gap_ge_5: 
    \forall integer a, b; b - a >= 5 ==> ldp(a, b) == 0;
*/

int computeLastDigit(int a, int b);

/*@ 
  requires \true;
  assigns \nothing;

  ensures 0 <= \result <= 9;

  ensures \result == ldp(a, b);

  behavior empty:
    assumes b <= a;
    ensures \result == 1;

  behavior zero:
    assumes b - a >= 5;
    ensures \result == 0;

  behavior small:
    assumes a < b && b - a < 5;
    ensures \result == ldp(a, b);

  complete behaviors empty, zero, small;
  disjoint behaviors empty, zero, small;
*/
int computeLastDigit(int a, int b) {

        int variable = 1;
        if (a == b) {
            return 1;
        } else if ((b - a) >= 5) {
            return 0;
        } else {
            /*@
              loop invariant i >= a + 1;
              loop invariant 0 <= variable <= 9;
              loop invariant variable == ldp(a, i - 1);
              loop invariant a < b ==> i <= b + 1;
              loop assigns i, variable;
              loop variant (i <= b + 1) ? (b + 1 - i) : 0;
            */
            for (int i = a + 1; i < b + 1; i++) {
                variable = (variable * (i % 10)) % 10;
            }
            return variable % 10;
        }
}
