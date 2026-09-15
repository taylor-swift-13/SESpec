#include <stdlib.h>

/*@
    requires \valid_read(arr + (0..arr_len-1));
    requires arr_len >= n && n > 0;
    ensures \result >= 0;
*/
int maxProduct(int * arr, int arr_len, int n);

int maxProduct(int * arr, int arr_len, int n) {

    /*@
        requires n > 0;
        allocates \result;
        ensures \valid(\result + (0..n-1));
    */
    int *mpis = (int *)malloc(sizeof(int) * (n));
    int mpis_len = n;

    /*@
        loop invariant 0 <= i <= n;
        loop invariant \valid(mpis + (0..n-1));
        loop assigns i, mpis[0..n-1];
        loop variant n - i;
    */
    for (int i = 0; i < n; i++) {
        mpis[i] = arr[i];
    }

    /*@
        loop invariant 1 <= i <= n;
        loop invariant \valid(mpis + (0..n-1));
        loop assigns i, j, mpis[0..n-1];
        loop variant n - i;
    */
    for (int i = 1; i < n; i++) {
        /*@
            loop invariant 0 <= j <= i;
            loop invariant \valid(mpis + (0..n-1));
            loop assigns j, mpis[0..n-1];
            loop variant i - j;
        */
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && mpis[i] < (mpis[j] * arr[i])) {
                mpis[i] = mpis[j] * arr[i];
            }
        }
    }

    int max = mpis[0];

    /*@
        loop invariant 1 <= i <= n;
        loop invariant \valid(mpis + (0..n-1));
        loop assigns i, max;
        loop variant n - i;
    */
    for (int i = 1; i < n; i++) {
        if (mpis[i] > max) {
            max = mpis[i];
        }
    }

    /*@
        frees mpis;
        ensures \result >= 0;
    */
    free(mpis);
    return max;
}
