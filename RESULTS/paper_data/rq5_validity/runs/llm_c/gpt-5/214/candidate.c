#include <stdlib.h>

/*@ axiomatic CatalanMath {
  logic integer cat(integer n);
  logic integer cat_prefix(integer n, integer j);

  axiom cat_base: cat(0) == 1;

  axiom cat_prefix_base:
    \forall integer n; cat_prefix(n, 0) == 0;

  axiom cat_prefix_step:
    \forall integer n, j;
      j > 0 ==> cat_prefix(n, j) == cat_prefix(n, j - 1) + cat(j - 1) * cat(n - 1 - (j - 1));

  axiom cat_defn:
    \forall integer n; n > 0 ==> cat(n) == cat_prefix(n, n);
} */

/*@ requires num >= 0;
    assigns \nothing;
    ensures \result == cat(num);
*/
int catalanNumber(int num);

int catalanNumber(int num) {

        int *catalan = (int *)malloc(sizeof(int) * (num + 1));
        /*@ assume \valid(catalan + (0 .. num)); */

int catalan_len = num + 1;
        catalan[0] = 1;
        /*@ assert catalan[0] == cat(0); */

        /*@
          loop invariant 1 <= i <= num + 1;
          loop invariant \valid(catalan + (0 .. num));
          loop invariant \forall integer k; 0 <= k < i ==> catalan[k] == cat(k);
          loop assigns i, catalan[0 .. num];
          loop variant num - i + 1;
        */
        for (int i = 1; i <= num; i++) {
            catalan[i] = 0;
            /*@
              loop invariant 0 <= j <= i;
              loop invariant \forall integer k; 0 <= k < i ==> catalan[k] == cat(k);
              loop invariant catalan[i] == cat_prefix(i, j);
              loop assigns j, catalan[i];
              loop variant i - j;
            */
            for (int j = 0; j < i; j++) {
                catalan[i] += catalan[j] * catalan[i - j - 1];
            }
            /*@ assert catalan[i] == cat(i); */
        }
        /*@ assert catalan[num] == cat(num); */
        return catalan[num];
}
