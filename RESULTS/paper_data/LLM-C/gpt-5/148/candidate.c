/*@ axiomatic Pow2 {
    logic integer pow2(integer k);
    axiom pow2_base: pow2(0) == 1;
    axiom pow2_step: \forall integer k; k >= 0 ==> pow2(k+1) == 2 * pow2(k);
    axiom pow2_pos: \forall integer k; k >= 0 ==> pow2(k) > 0;
  }
*/

int isPowerOfTwo(int n);

/*@ 
  assigns \nothing;
  ensures 0 <= \result <= 1;
  ensures \result == (\old(n) > 0 && (\exists integer k; k >= 0 && \old(n) == pow2(k)));
  ensures \old(n) > 0 ==> (n % 2 == 1 && (\exists integer k; k >= 0 && \old(n) == n * pow2(k)));
*/
int isPowerOfTwo(int n) {

        if(n <= 0) {
            return 0;
        }
        /*@ 
          loop invariant n > 0;
          loop invariant \at(n,Pre) > 0 ==> (\exists integer k; k >= 0 && \at(n,Pre) == n * pow2(k));
          loop assigns n;
          loop variant n;
        */
        while (n % 2 == 0) {
            n /= 2;
        }
        return n == 1;
}
