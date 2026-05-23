#include <stdlib.h>

/*@
    requires number > 0;
    requires p > 0;
    assigns \nothing;
    ensures \result == 0 || (\result > 0 && \result <= number);
*/
int getNumber(int number, int p);

int getNumber(int number, int p) {

    /*@
        allocates result, b;
        ensures \valid(result + (0..number-1));
        ensures \valid(b + (0..number-1));
    */
    int *result = (int *)malloc(sizeof(int) * (number));
    int result_len = number;

    /*@
        allocates b;
        ensures \valid(b + (0..number-1));
    */
    int *b = (int *)malloc(sizeof(int) * (number));
    int b_len = number;

    int c, j = 0;

    /*@
        loop invariant 0 <= c <= number;
        loop invariant \forall integer k; 0 <= k < c ==> result[k] == k + 1;
        loop assigns c, result[0..number-1];
    */
    for (c = 0; c < number; c++) {
        result[c] = c + 1;
    }

    /*@
        loop invariant 0 <= c <= number;
        loop invariant 0 <= j <= p;
        loop invariant \forall integer k; 0 <= k < c ==> b[k] == result[k];
        loop assigns c, j, b[0..number-1];
    */
    for (c = 0; c < number; c++) {
        b[c] = result[c];
        if (result[c] % 2 != 0) {
            j++;
            if (j == p) {
                free(result);
                free(b);
                return result[c];
            }
        }
    }

    /*@
        loop invariant 0 <= c <= number;
        loop invariant 0 <= j <= p;
        loop invariant \forall integer k; 0 <= k < c ==> b[k] == result[k];
        loop assigns c, j, b[0..number-1];
    */
    for (c = 0; c < number; c++) {
        b[c] = result[c];
        if (result[c] % 2 == 0) {
            j++;
            if (j == p) {
                free(result);
                free(b);
                return result[c];
            }
        }
    }

    free(result);
    free(b);
    return 0;
}
