#include <stdlib.h>

/*@
    requires n >= 1;
    assigns \nothing;
    ensures \result >= 0;
    ensures \result < 1000000000;
*/
int getPell(int n);

 /*@
    requires n >= 1;
    assigns \nothing;
    ensures \result >= 0;
    ensures \result < 1000000000;
*/
int getPell(int n) {

        int *pell = (int *)malloc(sizeof(int) * (n + 1));
int pell_len = n + 1;
        pell[0] = 0;
        pell[1] = 1;
        /*@
            loop invariant 2 <= i <= n + 1;
            loop invariant pell[0] == 0;
            loop invariant pell[1] == 1;
            loop invariant \forall integer k; 2 <= k < i ==> 0 <= pell[k] < 1000000000;
            loop assigns i, pell[2..n];
            loop variant n - i + 1;
        */
        for (int i = 2; i <= n; i++) {
            pell[i] = (2 * pell[i - 1] + pell[i - 2]) % 1000000000;
        }
        return pell[n];
}
