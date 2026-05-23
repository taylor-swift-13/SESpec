#include <stdlib.h>

/*@ axiomatic PellModAxioms {
  logic integer PellMod(integer k);
  axiom PellMod0: PellMod(0) == 0;
  axiom PellMod1: PellMod(1) == 1;
  axiom PellModRec:
    \forall integer k; k >= 2 ==> PellMod(k) == (2 * PellMod(k - 1) + PellMod(k - 2)) % 1000000000;
} */

/*@ 
  requires n >= 1;
  requires n + 1 <= 2147483647;
  requires \forall integer i; 2 <= i <= n ==> 2 * PellMod(i - 1) + PellMod(i - 2) <= 2147483647;
  ensures 0 <= \result < 1000000000;
  ensures \result == PellMod(n);
  assigns \nothing;
*/
int getPell(int n);

int getPell(int n) {
        /*@ assert n >= 1; */
        int *pell = (int *)malloc(sizeof(int) * (n + 1));
        /*@ assert pell != \null; */
        /*@ assert \valid(pell + (0..n)); */
        int pell_len = n + 1;
        /*@ assert pell_len == n + 1; */
        pell[0] = 0;
        /*@ assert pell[0] == PellMod(0); */
        /*@ assert 0 <= pell[0] < 1000000000; */
        pell[1] = 1;
        /*@ assert pell[1] == PellMod(1); */
        /*@ assert 0 <= pell[1] < 1000000000; */
        /*@ 
          loop invariant 2 <= i <= n + 1;
          loop invariant \valid(pell + (0..n));
          loop invariant \forall integer k; 0 <= k < i ==> pell[k] == PellMod(k);
          loop invariant \forall integer k; 0 <= k < i ==> 0 <= pell[k] < 1000000000;
          loop assigns pell[2..n], i;
          loop variant n - i;
        */
        for (int i = 2; i <= n; i++) {
            pell[i] = (2 * pell[i - 1] + pell[i - 2]) % 1000000000;
            /*@ assert pell[i] == PellMod(i); */
            /*@ assert 0 <= pell[i] < 1000000000; */
        }
        /*@ assert pell[n] == PellMod(n); */
        /*@ assert 0 <= pell[n] < 1000000000; */
        return pell[n];
}
