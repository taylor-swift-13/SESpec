#include <stdlib.h>

/*@
    requires \true;
    behavior negative:
        assumes size < 0;
        ensures \result == -1;
    behavior out_of_range:
        assumes size >= 4;
        ensures \result == 0;
    behavior in_range:
        assumes 0 <= size < 4;
        ensures \result == 1;
    complete behaviors negative, out_of_range, in_range;
    disjoint behaviors negative, out_of_range, in_range;
*/
int func(int size);

int func(int size) {
    if (size < 0) return -1;
    if (size < 0 || size >= 4) return 0;
    int *a = (int *)malloc(sizeof(int) * 4);
    a[size] = 0;
    return 1;
}
