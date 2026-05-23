#include <stdlib.h>

/*@
    requires seed >= 0;
    ensures \result >= 0;
*/
int findLucas(int seed);

/*@
    requires seed >= 0;
    ensures \result >= 0;
    assigns \nothing;
*/
int findLucas(int seed) {

    /*@
        requires seed >= 0;
        ensures \valid(result+(0..result_len-1));
        ensures result[0] == 2;
        ensures result[1] == 1;
        ensures \forall integer c; 2 <= c <= seed ==> result[c] == result[c-1] + result[c-2];
        assigns result[0..result_len-1];
    */
    int *result = (int *)malloc(sizeof(int) * (seed + 1));
    int result_len = seed + 1;
    result[0] = 2;
    result[1] = 1;

    /*@
        loop invariant 2 <= c <= seed + 1;
        loop invariant \forall integer k; 2 <= k < c ==> result[k] == result[k-1] + result[k-2];
        loop assigns c, result[2..seed];
        loop variant seed - c;
    */
    for (int c = 2; c <= seed; c++) {
        result[c] = result[c - 1] + result[c - 2];
    }

    int final_result = result[seed];
    free(result);
    return final_result;
}
