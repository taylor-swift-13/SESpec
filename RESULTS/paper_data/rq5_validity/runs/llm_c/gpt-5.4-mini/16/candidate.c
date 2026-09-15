#include <stdlib.h>

/*@
    requires size >= 0;
    requires size < 4;
    ensures \result == 1;
    assigns \nothing;
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
