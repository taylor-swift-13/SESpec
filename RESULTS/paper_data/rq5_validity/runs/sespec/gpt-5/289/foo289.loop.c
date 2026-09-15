
#include <stdlib.h>

/*@ 
  requires c >= 1;
  ensures \result == \result;
*/
int foo289(int c) {

    int *j = (int *)malloc(sizeof(int) * (c + 1));
    int j_len = c + 1;
    j[0] = 2;
    j[1] = 1;

    /*@
      loop invariant 2 <= d <= c + 1;
      loop invariant 0 <= d <= j_len;
      loop invariant j_len == c + 1;
      loop invariant j[0] == 2;
      loop invariant j[1] == 1;
      loop invariant \forall integer k; 2 <= k < d ==> j[k] == j[k-1] + 2 * j[k-2];
      loop invariant \forall integer k; 0 <= k < d ==> k < j_len;
      loop assigns d, j[0..j_len-1];
    */
    for (int d = 2; d <= c; d++) {
        j[d] = j[d - 1]
                + 2 * j[d - 2];
    }

    return j[c];
}
