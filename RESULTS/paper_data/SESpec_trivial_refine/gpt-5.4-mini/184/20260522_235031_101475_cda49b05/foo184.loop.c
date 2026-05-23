
/*@
requires 1 <= n;
requires n <= \max_int - 1;
*/

int foo184(int n) {

        int *sumOfPrimeDivisors = (int *)malloc(sizeof(int) * (n + 1));
        int sumOfPrimeDivisors_len = n + 1;
        sumOfPrimeDivisors[0] = 0;
        sumOfPrimeDivisors[1] = 0;

        /*@
          loop invariant 2 <= i <= n + 1;
          loop assigns i, sumOfPrimeDivisors[..];
        */
        for (int i = 2; i <= n; i++) {
            if (sumOfPrimeDivisors[i] == 0) {
                /*@
                  loop invariant i <= j <= n + i;
                  loop invariant \forall integer k; i <= k < j && k <= n && k % i == 0 ==> sumOfPrimeDivisors[k] >= i;
                  loop assigns j, sumOfPrimeDivisors[j];
                */
                for (int j = i; j <= n; j += i) {
                    sumOfPrimeDivisors[j] += i;
                }
            }
        }

        return sumOfPrimeDivisors[n];
}
