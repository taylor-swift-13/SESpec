
#include <stdlib.h>

/*@ logic integer seq_val(integer n) =
      n <= 0 ? 0 :
      n == 1 ? 1 :
      ((2 * seq_val(n - 1) + seq_val(n - 2)) % 1000000000); */
/*@
  assigns \nothing;
  ensures (p <= 0) ==> \result == 0;
  ensures (p == 1) ==> \result == 1;
  ensures (p >= 2) ==> \result == seq_val(p);
  ensures 0 <= \result < 1000000000;
*/
int foo294(int p) {

    int *arr = (int *)malloc(sizeof(int) * (p + 1));
    int arr_len = p + 1;
    arr[0] = 0;
    arr[1] = 1;
    
            
    /* >>> LOOP INVARIANT TO FILL <<< */
        
    /*@
      loop invariant 2 <= count <= p + 1;
      loop invariant arr_len == p + 1;
      loop invariant \valid(arr + (0 .. arr_len - 1));
      loop invariant arr[0] == 0 && arr[1] == 1;
      loop invariant \forall integer k; 2 <= k < count ==> arr[k] == ( (2 * arr[k-1] + arr[k-2]) % 1000000000 );
      loop invariant \forall integer k; 0 <= k < count ==> 0 <= arr[k] < 1000000000;
      loop assigns count, arr[..];
    */
    for (int count = 2; count <= p; count++) {
        arr[count] = (2 * arr[count - 1]
                + arr[count - 2]) % 1000000000;
    }
            
    return arr[p];
}
