
#include <stdlib.h>

/*@ logic integer fib295(integer n) =
      n <= 0 ? 2 :
      n == 1 ? 1 :
      fib295(n - 1) + fib295(n - 2);
*/

/*@
    requires num >= 1;
    ensures \result == fib295(num);
*/
int foo295(int num) {
    int *result = (int *)malloc(sizeof(int) * (num + 1));
    int result_len = num + 1;
    result[0] = 2;
    result[1] = 1;

    /*@
      loop invariant 2 <= l <= num + 1;
      loop invariant result[0] == fib295(0);
      loop invariant result[1] == fib295(1);
      loop invariant l >= 2 ==> result[l - 1] == fib295(l - 1);
      loop invariant l >= 3 ==> result[l - 2] == fib295(l - 2);
      loop assigns l, result[0..num];
    */
    for (int l = 2; l <= num; l++) {
        result[l] = result[l - 1] + result[l - 2];
    }

    return result[num];
}
