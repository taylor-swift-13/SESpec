#include <stdlib.h>

/*@
    requires n >= 0;
    ensures \result >= 0;
    assigns \nothing;
*/
int catalanNumber(int n);

/*@
    requires n >= 0;
    ensures \result >= 0;
    assigns \nothing;
*/
int catalanNumber(int n) {

    int *arr = (int *)malloc(sizeof(int) * (n + 1));
    int arr_len = n + 1;

    /*@
        loop invariant 0 <= c <= n + 1;
        loop invariant \forall integer i; 0 <= i < c ==> arr[i] >= 0;
        loop assigns c, arr[0..n];
    */
    arr[0] = 1;
    for (int c = 1; c <= n; c++) {
        arr[c] = 0;

        /*@
            loop invariant 0 <= k <= c;
            loop invariant arr[c] >= 0;
            loop assigns k, arr[c];
        */
        for (int k = 0; k < c; k++) {
            arr[c] += arr[k] * arr[c - k - 1];
        }
    }

    int result = arr[n];
    free(arr);
    return result;
}
