
#include <stdlib.h>

/*@
  predicate arr_rec_ok(int* arr, int* C, integer upto) =
    (upto >= 0) ==>
      (\forall integer k; 0 <= k <= upto ==>
        ((k == 0) ==> (arr[0] == 1)) &&
        ((k == 1) ==> (arr[1] == 0)) &&
        ((k >= 2) ==> (arr[k] == arr[k-2] + 2 * C[k-1]))
      );
*/

/*@
  predicate C_rec_ok(int* C, int* arr, integer upto) =
    (upto >= 0) ==>
      (\forall integer k; 0 <= k <= upto ==>
        ((k == 0) ==> (C[0] == 0)) &&
        ((k == 1) ==> (C[1] == 1)) &&
        ((k >= 2) ==> (C[k] == arr[k-1] + C[k-2]))
      );
*/

int foo51_c193(int count) {

    int *arr = (int *)malloc(sizeof(int) * (count + 1));
    int arr_len = count + 1;
    int *C = (int *)malloc(sizeof(int) * (count + 1));
    int C_len = count + 1;
    arr[0] = 1;
    arr[1] = 0;
    C[0] = 0;
    C[1] = 1;

    /*@
      loop invariant 2 <= w;
      loop invariant arr_len == count + 1;
      loop invariant C_len == count + 1;
      loop assigns w, arr[0..arr_len-1], C[0..C_len-1];
    */
    for (int w = 2; w <= count; w++) {
        arr[w] = arr[w - 2]
                 + 2 * C[w - 1];
        C[w] = arr[w - 1] + C[w - 2];
    }

    return arr[count];
}
