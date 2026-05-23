#include <stdlib.h>

/*@
  logic integer catalan_rec(integer n) =
    n == 0 ? 1 : (\sum integer j; 0 <= j < n; catalan_rec(j) * catalan_rec(n - j - 1));
*/

/*@
    requires num >= 0;
    assigns \nothing;
    ensures \result == catalan_rec(num);
*/
int catalanNumber(int num) {

        int *catalan = (int *)malloc(sizeof(int) * (num + 1));
        /*@ assert num >= 0; */
        /*@ assert \fresh(catalan, (num + 1) * sizeof(int)); */ /* allocation modeled as fresh */
        /*@ assert \valid(catalan + (0 .. num)); */

        int catalan_len = num + 1;
        catalan[0] = 1;
        /*@
          loop invariant 1 <= i && i <= num + 1;
          loop invariant catalan[0] == catalan_rec(0);
          loop invariant \forall integer k; 0 <= k < i ==> catalan[k] == catalan_rec(k);
          loop assigns i, catalan[0 .. num];
          loop variant num - i + 1;
        */
        for (int i = 1; i <= num; i++) {
            catalan[i] = 0;
            /*@
              loop invariant 0 <= j && j <= i;
              loop invariant catalan[i] == \sum integer t; 0 <= t < j; catalan[t] * catalan[i - t - 1];
              loop assigns j, catalan[i];
              loop variant i - j;
            */
            for (int j = 0; j < i; j++) {
                catalan[i] += catalan[j] * catalan[i - j - 1];
            }
        }
        int result = catalan[num];
        return result;
}
