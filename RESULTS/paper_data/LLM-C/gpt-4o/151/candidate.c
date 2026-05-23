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
        allocates result[0..number-1];
        allocates b[0..number-1];
        ensures \valid(result+(0..number-1));
        ensures \valid(b+(0..number-1));
    */
    int *result = (int *)malloc(sizeof(int) * (number));
    int result_len = number;
    int *b = (int *)malloc(sizeof(int) * (number));
    int b_len = number;
    int c, ii = 0;

    /*@
        loop invariant 0 <= c <= number;
        loop invariant \valid(result+(0..number-1));
        loop invariant \forall integer i; 0 <= i < c ==> result[i] == i + 1;
        loop assigns c, result[0..number-1];
    */
    for (c = 0; c < number; c++) {
        result[c] = c + 1;
    }

    /*@
        loop invariant 0 <= c <= number;
        loop invariant 0 <= ii <= p;
        loop invariant \valid(b+(0..number-1));
        loop invariant \forall integer i; 0 <= i < c ==> b[i] == result[i];
        loop assigns c, ii, b[0..number-1];
    */
    for (c = 0; c < number; c++) {
        b[c] = result[c];
        if (result[c] % 2 != 0) {
            ii++;
            if (ii == p) {
                free(result);
                free(b);
                return result[c];
            }
        }
    }

    /*@
        loop invariant 0 <= c <= number;
        loop invariant 0 <= ii <= p;
        loop invariant \valid(b+(0..number-1));
        loop invariant \forall integer i; 0 <= i < c ==> b[i] == result[i];
        loop assigns c, ii, b[0..number-1];
    */
    for (c = 0; c < number; c++) {
        b[c] = result[c];
        if (result[c] % 2 == 0) {
            ii++;
            if (ii == p) {
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
