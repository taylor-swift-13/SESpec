
#include <stdlib.h>

/*@
  assigns \nothing;
  ensures \result == fib(seed);
*/
int foo296(int seed) {

    int *result = (int *)malloc(sizeof(int) * (seed + 1));
    int result_len = seed + 1;
    result[0] = 2;
    result[1] = 1;

    /* >>> LOOP INVARIANT TO FILL <<< */
    /*@
      loop invariant 2 <= c <= seed + 1;
      loop invariant result_len == seed + 1;
      loop invariant \valid(result + (0 .. result_len - 1));
      loop invariant result[0] == 2;
      loop invariant result[1] == 1;
      loop invariant \forall integer k; 0 <= k < c ==> result[k] == fib(k);
      loop invariant \forall integer k; 2 <= k < c ==> result[k] == result[k - 1] + result[k - 2];
      loop assigns c, result[..];
    */
    for (int c = 2; c <= seed; c++) {
        result[c] = result[c - 1]
                  + result[c - 2];
    }

    return result[seed];
}
