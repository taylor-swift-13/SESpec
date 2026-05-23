#include <stdlib.h>

/*@ 
  logic integer Pell_mod(integer k) =
    k == 0 ? 0 :
    k == 1 ? 1 :
    (2*Pell_mod(k-1) + Pell_mod(k-2)) % 1000000000;
*/

/*@
    requires n >= 1;
    assigns \nothing;
    ensures 0 <= \result < 1000000000;
    ensures \result == Pell_mod(n);
*/
int getPell(int n) {

        int *pell = (int *)malloc(sizeof(int) * (n + 1));
int pell_len = n + 1;
        pell[0] = 0;
        pell[1] = 1;
        /*@
            loop invariant 2 <= i <= n+1;
            loop invariant \forall integer k; 0 <= k < i ==> pell[k] == Pell_mod(k);
            loop invariant \forall integer k; 0 <= k < i ==> 0 <= pell[k] < 1000000000;
            loop assigns i, pell[2..n];
            loop variant n - i + 1;
        */
        for (int i = 2; i <= n; i++) {
            pell[i] = (2 * pell[i - 1] + pell[i - 2]) % 1000000000;
        }
        return pell[n];
}
