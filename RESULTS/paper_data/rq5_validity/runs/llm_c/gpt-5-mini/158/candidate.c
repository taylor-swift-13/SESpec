#include <stdlib.h>

int smallestMultiple(int n);

/*@
    requires n >= 0;
    behavior small:
        assumes n <= 2;
        assigns \nothing;
        ensures \result == n;
    behavior large:
        assumes n > 2;
        assigns \nothing; // (no visible global side-effects; heap allocation is internal)
        ensures \result > 0;
        ensures \forall integer k; 1 <= k <= n ==> \result % k == 0;
    complete behaviors small, large;
    disjoint behaviors small, large;
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
            loop invariant \forall integer t; 0 <= t < j ==> factors[t] == t + 1;
            loop assigns j, factors[0..n-1];
            loop variant n - j;
        */
        for (int j = 0; j < n; j++) {
            factors[j] = j + 1;
        }
        /*@
            loop invariant i >= 2*n;
            loop invariant i % n == 0;
            loop assigns i;
        */
        while (1) {
            /*@
                loop invariant 0 <= a <= n;
                loop invariant (\forall integer t; 0 <= t < a ==> i % factors[t] == 0);
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
