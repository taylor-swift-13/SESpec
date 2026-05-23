
#include <stdlib.h>

/*@ 
  logic integer rec_val(integer i) =
    i < 0 ? 0 :
    i == 0 ? 2 :
    i == 1 ? 1 :
    rec_val(i - 1) + 2 * rec_val(i - 2);
*/

/*@
  requires c >= 1;
  assigns \nothing;
*/
int foo291(int c) {

    int *j = (int *)malloc(sizeof(int) * (c + 1));
    int j_len = c + 1;
    j[0] = 2;
    j[1] = 1;

    /*@ 
      loop invariant 2 <= p <= c + 1;
      loop invariant j_len == c + 1;
      loop invariant j[0] == 2;
      loop invariant j[1] == 1;
      loop invariant \forall integer k; 2 <= k < p ==> j[k] == j[k-1] + 2 * j[k-2];
      loop invariant (p <= c) ==> (0 <= p-2 < j_len && 0 <= p-1 < j_len && 0 <= p < j_len);
      loop assigns p, j[0..j_len-1];
    */
    for (int p = 2; p <= c; p++) {
        j[p] = j[p - 1]
             + 2 * j[p - 2];
    }

    return j[c];
}
