
#include <stdlib.h>

/*@
  ensures \result == A_seq(count);
  assigns \nothing;
*/
int foo193(int count) {

    int *arr = (int *)malloc(sizeof(int) * (count + 1));
    int arr_len = count + 1;
    int *C = (int *)malloc(sizeof(int) * (count + 1));
    int C_len = count + 1;
    arr[0] = 1;
    arr[1] = 0;
    C[0] = 0;
    C[1] = 1;
        
    /* >>> LOOP INVARIANT TO FILL <<< */
        
    /*@
      loop invariant 2 <= w <= count + 1;
      loop invariant arr_len == count + 1 && C_len == count + 1;
      loop invariant \valid(arr + (0 .. arr_len-1));
      loop invariant \valid(C + (0 .. C_len-1));
      loop invariant arr[0] == 1 && arr[1] == 0;
      loop invariant C[0] == 0 && C[1] == 1;
      loop invariant \forall integer k; 0 <= k < w ==> arr[k] == A_seq(k);
      loop invariant \forall integer k; 0 <= k < w ==> C[k] == C_seq(k);
      loop assigns w, arr[..], C[..];
    */
    for (int w = 2; w <= count; w++) {
        arr[w] = arr[w - 2]
                + 2 * C[w - 1];
        C[w] = arr[w - 1] + C[w - 2];
    }
            
    return arr[count];
}
