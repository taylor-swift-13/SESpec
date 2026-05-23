#include <stdlib.h>

/*@
    requires index >= 0 && index < 4;
    ensures \result == 1;
    assigns \nothing;

    behavior out_of_bounds:
        assumes index < 0 || index >= 4;
        ensures \result == 0;
        assigns \nothing;

    behavior in_bounds:
        assumes index >= 0 && index < 4;
        ensures \result == 1;
        assigns \nothing;

    complete behaviors out_of_bounds, in_bounds;
    disjoint behaviors out_of_bounds, in_bounds;
*/
int func(int index) {
    if (index < 0 || index >= 4) return 0;
    int *a = (int *)malloc(sizeof(int) * 4);
    /*@
        loop invariant 0 <= index < 4;
        loop assigns a[index];
    */
    a[index] = 0;
    return 1;
}
