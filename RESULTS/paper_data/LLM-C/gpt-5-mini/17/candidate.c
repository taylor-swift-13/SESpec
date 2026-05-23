#include <stdlib.h>

/*@
    ensures \result == 0 || \result == 1;
    behavior out_of_range:
        assumes index < 0 || index >= 4;
        ensures \result == 0;
        assigns \nothing;
    behavior in_range:
        assumes 0 <= index && index < 4;
        ensures \result == 1;
        assigns \nothing;
    complete behaviors out_of_range, in_range;
    disjoint behaviors out_of_range, in_range;
*/
int func(int index);

int func(int index) {
    if (index < 0 || index >= 4) return 0;
    int *a = (int *)malloc(sizeof(int) * 4);
    a[index] = 0;
    return 1;
}
