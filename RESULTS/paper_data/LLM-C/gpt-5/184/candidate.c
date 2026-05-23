#include <stdlib.h>

/*@ predicate is_prime(integer k) =
      k >= 2 &&
      (\forall integer d; 2 <= d <= k-1 ==> k % d != 0);
*/

/*@ 
  requires n >= 1;
  assigns \nothing;
  ensures 0 <= \result <= n;
  ensures n == 1 ==> \result == 0;
  ensures n >= 2 ==> \result >= 2;
  ensures is_prime(n) ==> \result == n;
*/
int sum(int n);

int sum(int n) {

        int *sumOfPrimeDivisors = (int *)malloc(sizeof(int) * (n + 1));
/*@ assert sumOfPrimeDivisors != \null; */
/*@ assert \valid(sumOfPrimeDivisors + (0..n)); */
/*@ assume \forall integer k; 0 <= k <= n ==> sumOfPrimeDivisors[k] == 0; */

int sumOfPrimeDivisors_len = n + 1;
/*@ assert sumOfPrimeDivisors_len == n + 1; */
        sumOfPrimeDivisors[0] = 0;
        sumOfPrimeDivisors[1] = 0;
/*@ assert sumOfPrimeDivisors[0] == 0 && sumOfPrimeDivisors[1] == 0; */

        /*@ 
          loop invariant 2 <= i <= n + 1;
          loop invariant \valid(sumOfPrimeDivisors + (0..n));
          loop assigns sumOfPrimeDivisors[0..n];
          loop variant n - i + 1;
        */
        for (int i = 2; i <= n; i++) {
            if (sumOfPrimeDivisors[i] == 0) {
                /*@
                  loop invariant i <= j <= n + (i > 0 ? i : 0);
                  loop invariant j % i == 0;
                  loop invariant \valid(sumOfPrimeDivisors + (0..n));
                  loop assigns sumOfPrimeDivisors[0..n], j;
                  loop variant n - j;
                */
                for (int j = i; j <= n; j += i) {
                    sumOfPrimeDivisors[j] += i;
                }
            }
        }

        /*@ assert 0 <= n < sumOfPrimeDivisors_len; */
        return sumOfPrimeDivisors[n];
}
