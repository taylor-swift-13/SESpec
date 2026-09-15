#include <stdlib.h>

/*@
    requires n >= 0;
    assigns \nothing;
    ensures \result == (\sum integer d; 2 <= d <= n &&
                                (\forall integer m; 2 <= m < d ==> d % m != 0) &&
                                n % d == 0; d);
*/
int sum(int n) {

        int *sumOfPrimeDivisors = (int *)malloc(sizeof(int) * (n + 1));
        int sumOfPrimeDivisors_len = n + 1;
        /*@ assert sumOfPrimeDivisors_len == n + 1; */
        /*@ assert \valid(sumOfPrimeDivisors + (0..n)); */
        sumOfPrimeDivisors[0] = 0;
        if (n >= 1) sumOfPrimeDivisors[1] = 0;

        /*@
            loop invariant 2 <= i <= n+1;
            loop invariant \valid(sumOfPrimeDivisors + (0..n));
            loop assigns i, sumOfPrimeDivisors[0..n];
            loop variant n - i + 1;
        */
        for (int i = 2; i <= n; i++) {
            if (sumOfPrimeDivisors[i] == 0) {
                /*@
                    loop invariant i <= j <= n+1;
                    loop invariant \valid(sumOfPrimeDivisors + (0..n));
                    loop assigns j, sumOfPrimeDivisors[0..n];
                    loop variant n - j + 1;
                */
                for (int j = i; j <= n; j += i) {
                    sumOfPrimeDivisors[j] += i;
                }
            }
        }

        int result = sumOfPrimeDivisors[n];
        free(sumOfPrimeDivisors);
        return result;
}
