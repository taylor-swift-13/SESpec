#include <stdlib.h>

/*@
    requires seed >= 0;
    ensures \result >= 0 && \result < 1000000000;
*/
int getPell(int seed);

int getPell(int seed) {
    /*@
        requires seed >= 0;
        ensures \valid(arr+(0..seed));
        ensures arr[0] == 0;
        ensures arr[1] == 1;
        ensures \forall integer p; 2 <= p <= seed ==> arr[p] == (2 * arr[p - 1] + arr[p - 2]) % 1000000000;
        assigns arr[0..seed];
    */
    int *arr = (int *)malloc(sizeof(int) * (seed + 1));
    int arr_len = seed + 1;
    arr[0] = 0;
    arr[1] = 1;

    /*@
        loop invariant 2 <= p <= seed + 1;
        loop invariant \forall integer k; 2 <= k < p ==> arr[k] == (2 * arr[k - 1] + arr[k - 2]) % 1000000000;
        loop assigns p, arr[2..seed];
        loop variant seed - p;
    */
    for (int p = 2; p <= seed; p++) {
        arr[p] = (2 * arr[p - 1] + arr[p - 2]) % 1000000000;
    }

    return arr[seed];
}
