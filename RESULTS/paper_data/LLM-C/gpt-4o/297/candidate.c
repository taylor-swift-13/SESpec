#include <stdlib.h>

/*@
    requires seed >= 0;
    ensures \result == 2 || \result == 1 || \result > 1;
    assigns \nothing;
*/
int findLucas(int seed);

int findLucas(int seed) {
    /*@
        requires seed >= 0;
        ensures \result == 2 || \result == 1 || \result > 1;
        assigns \nothing;
    */
    int *result = (int *)malloc(sizeof(int) * (seed + 1));
    int result_len = seed + 1;
    result[0] = 2;
    result[1] = 1;
    for (int l = 2; l <= seed; l++) {
        result[l] = result[l - 1]
                + result[l - 2];
    }
    return result[seed];
}
