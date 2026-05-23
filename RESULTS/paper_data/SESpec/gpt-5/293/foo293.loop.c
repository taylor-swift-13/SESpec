
/*@
  logic integer fib2(integer n) =
    n == 0 ? 0 :
    n == 1 ? 1 :
    (2 * fib2(n - 1) + fib2(n - 2)) % 1000000000;
*/

#include <stdlib.h>

int foo293(int seed) {

    int *arr = (int *)malloc(sizeof(int) * (seed + 1));
    int arr_len = seed + 1;
    arr[0] = 0;
    arr[1] = 1;

    /*@
      loop invariant arr_len == seed + 1;
      loop assigns p, arr[0..arr_len-1];
    */
    for (int p = 2; p <= seed; p++) {
        arr[p] = (2 * arr[p - 1]
                + arr[p - 2]) % 1000000000;
    }

    return arr[seed];
}
