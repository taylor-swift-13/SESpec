#include <stdlib.h>

/*@
    requires value > 0;
    requires p > 0;
    ensures \result == 0 || (\exists integer k; 1 <= k <= value && 
             ((k % 2 != 0 && \count(1, k, \lambda integer x; x % 2 != 0) == p) || 
              (k % 2 == 0 && \count(1, k, \lambda integer x; x % 2 == 0) == p)));
    assigns \nothing;
*/
int getNumber(int value, int p);

int getNumber(int value, int p) {

    int *result = (int *)malloc(sizeof(int) * (value));
    int result_len = value;
    int *b = (int *)malloc(sizeof(int) * (value));
    int b_len = value;
    int c, j = 0;

    /*@
        loop invariant 0 <= c <= value;
        loop invariant \forall integer k; 0 <= k < c ==> result[k] == k + 1;
        loop assigns c, result[0..value-1];
        loop variant value - c;
    */
    for (c = 0; c < value; c++) {
        result[c] = c + 1;
    }

    /*@
        loop invariant 0 <= c <= value;
        loop invariant 0 <= j <= p;
        loop invariant \forall integer k; 0 <= k < c ==> b[k] == result[k];
        loop assigns c, j, b[0..value-1];
        loop variant value - c;
    */
    for (c = 0; c < value; c++) {
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
        loop invariant 0 <= c <= value;
        loop invariant 0 <= j <= p;
        loop invariant \forall integer k; 0 <= k < c ==> b[k] == result[k];
        loop assigns c, j, b[0..value-1];
        loop variant value - c;
    */
    for (c = 0; c < value; c++) {
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
