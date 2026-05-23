#include <stdlib.h>

/*@
    requires c >= 0;
    ensures \result >= 0;
    assigns \nothing;
*/
int catalanNumber(int c);

int catalanNumber(int c) {
    /*@
        requires c >= 0;
        ensures \result >= 0;
        assigns \nothing;
    */
    int *arr = (int *)malloc(sizeof(int) * (c + 1));
    int arr_len = c + 1;
    arr[0] = 1;
    for (int cat = 1; cat <= c; cat++) {
        arr[cat] = 0;
        for (int n = 0; n < cat; n++) {
            arr[cat] += arr[n]
                    * arr[cat - n - 1];
        }
    }
    return arr[c];
}
