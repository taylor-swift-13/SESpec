#include <stdlib.h>

int evenBinomialCoeffSum(int n);

/*@ requires n >= 0;
    requires n < 8 * (int)sizeof(int);
    behavior n_zero:
      assumes n == 0;
      ensures \result == 1;
    behavior n_pos:
      assumes n > 0;
      ensures \result == (1 << (n - 1));
    complete behaviors;
    disjoint behaviors;
    terminates \true;
*/
int evenBinomialCoeffSum(int n) {

        int sum = 0;
        int *dp = (int *)malloc(sizeof(int) * (n + 1));
int dp_len = n + 1;
/*@ assert dp != \null;
    assert \valid(dp + (0 .. n));
*/
        dp[0] = 1;
/*@ assert dp[0] == 1; */
        /*@ loop invariant 1 <= i <= n + 1;
            loop invariant \valid(dp + (0 .. n));
            loop invariant dp[0] == 1;
            loop invariant \forall integer k; 0 <= k < i ==> \initialized(dp + k);
            loop assigns i, dp[1 .. n];
            loop variant n - i + 1;
        */
        for (int i = 1; i <= n; i++) {
            /*@ loop invariant 0 <= j <= i;
                loop invariant \valid(dp + (0 .. n));
                loop invariant \forall integer k; 0 <= k < i ==> \initialized(dp + k);
                loop assigns j, dp[i];
                loop variant i - j;
            */
            for (int j = 0; j < i; j++) {
                dp[i] = dp[i] + dp[j];
            }
        }
        return dp[n];
}
