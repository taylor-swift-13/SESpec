#include <stdlib.h>

/*@
    requires index < 0 || index >= 4 || \true;
    ensures index < 0 || index >= 4 ==> \result == 0;
    ensures 0 <= index < 4 ==> \result == 1;
    assigns \nothing;
*/
int func(int index);

int func(int index) {
    if (index < 0 || index >= 4) return 0;
    int *a = (int *)malloc(sizeof(int) * 4);
    a[index] = 0;
    return 1;
}
