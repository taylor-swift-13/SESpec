#include <stdlib.h>

/*@
    requires unknown > 0 ==> \valid((int*)malloc(sizeof(int)));
    ensures \result == 1 ==> unknown > 0;
    ensures \result == 0 ==> unknown <= 0;
    assigns \nothing;
*/
int func(int unknown) {
    int arr_len = unknown > 0 ? 1 : 0;
    int *arr = arr_len ? (int *)malloc(sizeof(int) * arr_len) : 0;
    if (unknown > 0) arr[0] = 1;
    if (unknown > 0) return arr_len == 1 && arr[0] == 1;
    return arr_len == 0;
}
