
#include <stdlib.h>

/*@
  logic integer fibonacci_mod(int n) =
    n == 0 ? 0 :
    n == 1 ? 1 :
    (2 * fibonacci_mod((int)(n - 1)) + fibonacci_mod((int)(n - 2))) % 1000000000;
*/

/*@
  requires p >= 1; // Strengthened precondition to ensure the loop invariant holds initially
  ensures \result == fibonacci_mod(p);
*/
int foo294(int p) {
    int *arr = (int *)malloc(sizeof(int) * (p + 1));
    int arr_len = p + 1;
    arr[0] = 0;
    arr[1] = 1;

    /*@
      loop invariant 2 <= count <= p + 1;
                       arr[k] == fibonacci_mod((int)k);
      
      loop assigns count, arr[0..p];
    */
    for (int count = 2; count <= p; count++) {
        arr[count] = (2 * arr[count - 1] + arr[count - 2]) % 1000000000;
    }

    return arr[p];
}
