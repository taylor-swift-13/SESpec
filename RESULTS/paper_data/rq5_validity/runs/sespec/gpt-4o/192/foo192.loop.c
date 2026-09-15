
#include <stdlib.h>

/*@
  logic integer compute_w(int* w, int* C, integer index) =
    index < 2 ? (index == 0 ? 1 : 0)
              : compute_w(w, C, index - 2) + 2 * compute_C(w, C, index - 1);
*/

/*@
  logic integer compute_C(int* w, int* C, integer index) =
    index < 2 ? (index == 0 ? 0 : 1)
              : compute_w(w, C, index - 1) + compute_C(w, C, index - 2);
*/

int foo192(int count) {
    int *w = (int *)malloc(sizeof(int) * (count + 1));
    int w_len = count + 1;
    int *C = (int *)malloc(sizeof(int) * (count + 1));
    int C_len = count + 1;
    w[0] = 1;
    w[1] = 0;
    C[0] = 0;
    C[1] = 1;

    /*@
      loop invariant 2 <= index <= count + 1;
      loop invariant \forall integer k; 0 <= k < index ==> w[k] == compute_w(w, C, k);
      loop invariant \forall integer k; 0 <= k < index ==> C[k] == compute_C(w, C, k);
      loop invariant \forall integer k; 0 <= k < w_len ==> \valid(w + k);
      loop invariant \forall integer k; 0 <= k < C_len ==> \valid(C + k);
      loop assigns index, w[0..count], C[0..count];
    */
    for (int index = 2; index <= count; index++) {
        w[index] = w[index - 2] + 2 * C[index - 1];
        C[index] = w[index - 1] + C[index - 2];
    }

    return w[count];
}
