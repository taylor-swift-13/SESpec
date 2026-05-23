
/*@
  // No auxiliary predicates or logic functions are required.
*/

int foo396(int p) {

    int even = 0;

    /*@
      // Supplementary invariants capturing functional progress and structure
      loop invariant 1 <= c <= p + 1;
      loop invariant even == \sum(integer k; 1 <= k < c; (2*k)*(2*k)*(2*k)*(2*k));
      loop invariant even >= 0;
      loop invariant c == 1 ==> even == 0;
      loop invariant \forall integer k; 1 <= k < c ==> (2*k)*(2*k)*(2*k)*(2*k) >= 0;

      // Core loop invariants and assigns
      loop invariant p == \at(p,Pre);
      loop invariant (c <= \at(p,Pre)) ==> (even == \sum(integer k; 1 <= k < c; (2*k)*(2*k)*(2*k)*(2*k)));
      loop invariant (!(c <= \at(p,Pre))) ==> ((even == 0)&&(p == \at(p,Pre)));
      loop assigns c, count, even;
    */
    for (int c = 1; c <= p; c++) {
        int count = 2 * c;
        even = even + (count * count * count * count);
    }

    return even;
}
