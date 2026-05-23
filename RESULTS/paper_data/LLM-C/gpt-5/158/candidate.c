#include <stdlib.h>

/*@ 
  predicate multiple_of_all(integer m, integer n) = 
    m > 0 && (\forall integer k; 1 <= k <= n ==> m % k == 0);

  predicate minimal_multiple(integer m, integer n) = 
    multiple_of_all(m, n) &&
    (\forall integer t; 1 <= t < m ==> !(\forall integer k; 1 <= k <= n ==> t % k == 0));
*/

int smallestMultiple(int n);

/*@ 
  requires n >= 1;

  ensures minimal_multiple(\result, n);
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
        /*@ assert \forall integer k; 0 <= k < n ==> factors[k] == k + 1; */
        /*@ assert \forall integer p, q; 0 <= p < q < n ==> factors[p] < factors[q]; */

        /*@ 
          loop invariant n >= 1;
          loop invariant i >= 2 * n;
          loop invariant i % n == 0;
          loop assigns i;
        */
        while (1) {
            /*@ 
              loop invariant 0 <= a <= n;
              loop invariant i % n == 0;
              loop invariant \forall integer k; 0 <= k < a ==> i % factors[k] == 0;
              loop assigns a, i;
              loop variant n - a;
            */
            for (int a = 0; a < n; a++) {
                if (i % factors[a] != 0) {
                    i += n;
                    break;
                }
                if (factors[a] == factors[n - 1] && i % factors[a] == 0) {
                    /*@ assert \forall integer k; 0 <= k < n ==> i % factors[k] == 0; */
                    return i;
                }
            }
        }
}
