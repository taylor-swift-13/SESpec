#include <stdlib.h>

/*@
    requires n >= 0;
    ensures n <= 2 ==> \result == n;
    assigns \nothing;
*/
int smallestMultiple(int n);

 /*@
    requires n >= 0;
    assigns \nothing;
    ensures n <= 2 ==> \result == n;
*/
int smallestMultiple(int n) {

        if (n <= 2) {
            return n;
        }
        int i = n * 2;
        int *factors = (int *)malloc(sizeof(int) * (n));
        int factors_len = n;
        /*@
            loop invariant 0 <= j <= n;
            loop invariant \forall integer k; 0 <= k < j ==> factors[k] == k + 1;
            loop assigns j, factors[0..n-1];
            loop variant n - j;
        */
        for (int j = 0; j < n; j++) {
            factors[j] = j + 1;
        }
        /*@
            loop invariant i >= n * 2;
            loop assigns i;
            loop variant \at(i,Pre) >= i ? \at(i,Pre) - i : 0;
        */
        while (1) {
            /*@
                loop invariant 0 <= a <= n;
                loop assigns a, i;
                loop variant n - a;
            */
            for (int a = 0; a < n; a++) {
                if (i % factors[a] != 0) {
                    i += n;
                    break;
                }
                if (factors[a] == factors[n - 1] && i % factors[a] == 0) {
                    return i;
                }
            }
        }
}
