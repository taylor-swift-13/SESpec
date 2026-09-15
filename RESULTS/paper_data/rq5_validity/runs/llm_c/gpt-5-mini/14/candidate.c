#include <stdlib.h>

int func(int unknown);

/*@
    requires \true;
    behavior positive:
        assumes unknown > 0;
        ensures \result == 1;
    behavior non_positive:
        assumes unknown <= 0;
        ensures \result == 1;
    complete behaviors positive, non_positive;
    disjoint behaviors positive, non_positive;
*/
int func(int unknown) {
    int arr_len = unknown > 0 ? 1 : 0;
    int *arr = arr_len ? (int *)malloc(sizeof(int) * arr_len) : 0;
    if (unknown > 0) arr[0] = 1;
    if (unknown > 0) return arr_len == 1 && arr[0] == 1;
    return arr_len == 0;
}
