
/*@
  logic integer sum(int* array, integer begin, integer end) =
    end <= begin ? 0 : sum(array, begin, end - 1) + array[end - 1];
*/

/*@
  requires n >= 0;
  ensures \result >= 1;
*/
int foo240(int n) {

    int sum = 0;
    int *dp = (int *)malloc(sizeof(int) * (n + 1));
    int dp_len = n + 1;
    dp[0] = 1;

    /*@
      loop invariant 1 <= i <= n + 1;
      loop invariant \forall integer k; 0 <= k < i ==> dp[k] >= 1;
      loop assigns dp[1 .. n];
    */
    for (int i = 1; i <= n; i++) {
        /*@
          loop invariant 0 <= j <= i;
          loop assigns dp[i];
        */
        for (int j = 0; j < i; j++) {
            dp[i] = dp[i] + dp[j];
        }
    }

    return dp[n];
}
