#include <stdlib.h>

/*@
    behavior negative:
        assumes size < 0;
        ensures \result == -1;
        assigns \nothing;

    behavior out_of_bounds:
        assumes size >= 4;
        ensures \result == 0;
        assigns \nothing;

    behavior in_bounds:
        assumes 0 <= size && size < 4;
        ensures \result == 1;
        assigns \nothing;

    complete behaviors negative, out_of_bounds, in_bounds;
    disjoint behaviors negative, out_of_bounds, in_bounds;
*/
int func(int size);

int func(int size) {
    if (size < 0) return -1;
    if (size < 0 || size >= 4) return 0;
    int *a = (int *)malloc(sizeof(int) * 4);
    int i = a[size];
    (void)i;
    return 1;
}
