#include <stdlib.h>

/*@
    requires count >= 0;
    ensures \result >= 0;
*/
int countWays(int count);

/*@
    requires count >= 0;
    ensures \result >= 0;
    assigns \nothing;
*/
int countWays(int count) {

    /*@
        requires count >= 0;
        ensures \valid(arr+(0..count));
        ensures \valid(C+(0..count));
        assigns arr[0..count], C[0..count];
    */
    int *arr = (int *)malloc(sizeof(int) * (count + 1));
    int arr_len = count + 1;

    int *C = (int *)malloc(sizeof(int) * (count + 1));
    int C_len = count + 1;

    arr[0] = 1;
    arr[1] = 0;
    C[0] = 0;
    C[1] = 1;

    /*@
        loop invariant 2 <= w <= count;
        loop assigns arr[0..count], C[0..count];
    */
    for (int w = 2; w <= count; w++) {
        arr[w] = arr[w - 2]
                + 2 * C[w - 1];
        C[w] = arr[w - 1] + C[w - 2];
    }
    return arr[count];
}
