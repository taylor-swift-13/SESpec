#include <stdlib.h>

/*@
    requires b >= 0;
    ensures \result >= 0;
    assigns \nothing;
*/
int evenBinomialCoeffSum(int b);

int evenBinomialCoeffSum(int b) {

    int result = 0;
    /*@
        requires b >= 0;
        ensures \valid(arr + (0..b));
        assigns arr[0..b];
    */
    int *arr = (int *)malloc(sizeof(int) * (b + 1));
    int arr_len = b + 1;
    arr[0] = 1;

    /*@
        loop invariant 1 <= d <= b;
        loop invariant arr[0] = 1;
        loop assigns arr[0..b];
    */
    for (int d = 1; d <= b; d++) {
        /*@
            loop invariant 0 <= c <= d;
            loop assigns arr[0..b];
        */
        for (int c = 0; c < d; c++) {
            arr[d] = arr[d] + arr[c];
        }
    }
    return arr[b];
}
