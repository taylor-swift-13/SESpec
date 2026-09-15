#include <stdlib.h>

/*@
    requires n >= 0;
    ensures \result >= 0 && \result < 1000000000;
    assigns \nothing;
*/
int getPell(int n) {

    /*@
        requires n >= 0;
        ensures \valid(pell + (0..n));
        ensures pell[0] == 0;
        ensures pell[1] == 1;
        ensures \forall integer i; 2 <= i <= n ==> pell[i] == (2 * pell[i - 1] + pell[i - 2]) % 1000000000;
        assigns pell[0..n];
    */
    int *pell = (int *)malloc(sizeof(int) * (n + 1));
    int pell_len = n + 1;
    pell[0] = 0;
    pell[1] = 1;

    /*@
        loop invariant 2 <= i <= n + 1;
        loop invariant \forall integer j; 2 <= j < i ==> pell[j] == (2 * pell[j - 1] + pell[j - 2]) % 1000000000;
        loop assigns i, pell[2..n];
        loop variant n - i;
    */
    for (int i = 2; i <= n; i++) {
        pell[i] = (2 * pell[i - 1] + pell[i - 2]) % 1000000000;
    }

    int result = pell[n];
    free(pell);
    return result;
}
