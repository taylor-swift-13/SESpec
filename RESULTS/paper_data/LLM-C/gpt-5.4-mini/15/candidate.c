#include <stdlib.h>

/*@
    requires size >= 0;
    ensures \result == 0 <==> size >= 4;
    ensures \result == 1 <==> 0 <= size < 4;
    ensures \result == -1 <==> size < 0;
    assigns \nothing;
*/
int func(int size);

 /*@
    requires size >= 0;
    ensures \result == 0 <==> size >= 4;
    ensures \result == 1 <==> 0 <= size < 4;
    ensures \result == -1 <==> size < 0;
    assigns \nothing;
*/
int func(int size) {
    if (size < 0) return -1;
    if (size < 0 || size >= 4) return 0;
    int *a = (int *)malloc(sizeof(int) * 4);
    a[size] = 0;
    return 1;
}
