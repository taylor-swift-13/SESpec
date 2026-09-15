#include <stdlib.h>

/*@
    requires seed >= 0;
    ensures \result >= 0 && \result < 1000000000;
*/
int getPell(int seed);

int getPell(int seed) {
    /*@
        requires seed >= 0;
        ensures \valid(p+(0..seed));
        assigns p[0..seed];
    */
    int *p = (int *)malloc(sizeof(int) * (seed + 1));
    int p_len = seed + 1;
    p[0] = 0;
    p[1] = 1;

    /*@
        loop invariant 2 <= count <= seed + 1;
        loop invariant \forall integer i; 0 <= i < count ==> p[i] >= 0 && p[i] < 1000000000;
        loop assigns count, p[2..seed];
        loop variant seed - count;
    */
    for (int count = 2; count <= seed; count++) {
        p[count] = (2 * p[count - 1] + p[count - 2]) % 1000000000;
    }

    int result = p[seed];
    free(p);
    return result;
}
