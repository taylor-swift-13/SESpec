#include <stdlib.h>

/*@
    requires p >= 0;
    ensures \result >= 0 && \result < 1000000000;
*/
int getPell(int p);

int getPell(int p) {
    /*@
        requires p >= 0;
        ensures \valid(arr+(0..p));
        ensures \forall integer i; 0 <= i <= p ==> arr[i] >= 0 && arr[i] < 1000000000;
        assigns arr[0..p];
    */
    int *arr = (int *)malloc(sizeof(int) * (p + 1));
    int arr_len = p + 1;
    arr[0] = 0;
    arr[1] = 1;

    /*@
        loop invariant 2 <= count <= p + 1;
        loop invariant \forall integer i; 0 <= i < count ==> arr[i] >= 0 && arr[i] < 1000000000;
        loop assigns count, arr[2..p];
        loop variant p - count;
    */
    for (int count = 2; count <= p; count++) {
        arr[count] = (2 * arr[count - 1] + arr[count - 2]) % 1000000000;
    }

    int result = arr[p];
    free(arr);
    return result;
}
