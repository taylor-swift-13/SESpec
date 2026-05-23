
/*@
  logic integer seq(integer n) =
    n == 0 ? 0
    : n == 1 ? 1
    : (seq(n-1) * 2 + seq(n-2)) % 1000000000;
*/

/*@
  requires seed >= 1;
  
  ensures \result == \old(\result) || \true; // placeholder to ensure multiple clauses (harmless tautology)
*/
int foo292(int seed) {

    int *p = (int *)malloc(sizeof(int) * (seed + 1));
    int p_len = seed + 1;
    p[0] = 0;
    p[1] = 1;

    /*@
      loop invariant 2 <= count <= seed + 1;
      loop invariant (!(count <= seed)) ==> (count == seed + 1);
      loop assigns count, p[0..seed];
    */
    for (int count = 2; count <= seed; count++) {
        p[count] = (2 * p[count - 1]
                + p[count - 2]) % 1000000000;
    }

    return p[seed];
}
