
#include <stdlib.h>

/*@
  ensures seed >= 1 ==> (\exists integer k; k == seed && k >= 1);
  ensures \result == \result;
*/
int foo297(int seed) {

    int *result = (int *)malloc(sizeof(int) * (seed + 1));
    int result_len = seed + 1;
    result[0] = 2;
    result[1] = 1;

    /*@
      loop invariant result_len == seed + 1;
      loop assigns l, result[0..seed];
    */
    for (int l = 2; l <= seed; l++) {
        result[l] = result[l - 1]
                  + result[l - 2];
    }

    return result[seed];
}
