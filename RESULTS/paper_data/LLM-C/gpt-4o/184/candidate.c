#include <stdlib.h>

/*@
    requires n >= 0;
    ensures \result >= 0;
    assigns \nothing;
*/
int sum(int n);

/*@
    requires n >= 0;
    ensures \result >= 0;
    assigns \nothing;
*/
int sum(int n) {

    /*@
        requires n >= 0;
        ensures \valid(sumOfPrimeDivisors + (0..n));
        assigns sumOfPrimeDivisors[0..n];
    */
    int *sumOfPrimeDivisors = (int *)malloc(sizeof(int) * (n + 1));
    int sumOfPrimeDivisors_len = n + 1;
    sumOfPrimeDivisors[0] = 0;
    sumOfPrimeDivisors[1] = 0;

    /*@
        loop invariant 2 <= i <= n + 1;
        loop invariant \forall integer k; 0 <= k < i ==> sumOfPrimeDivisors[k] >= 0;
        loop assigns i, sumOfPrimeDivisors[2..n];
        loop variant n - i;
    */
    for (int i = 2; i <= n; i++) {
        if (sumOfPrimeDivisors[i] == 0) {
            /*@
                loop invariant i <= j <= n + 1;
                loop invariant \forall integer k; i <= k < j ==> sumOfPrimeDivisors[k] >= 0;
                loop assigns j, sumOfPrimeDivisors[i..n];
                loop variant n - j;
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
