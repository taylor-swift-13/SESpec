#include <stdlib.h>

/*@
    assigns \nothing;
    ensures \result == 0 || \result == 1;
*/
int f();

int f() {

    int *i = (int *)malloc(sizeof(int) * (10));
int i_len = 10;
    return i[3] == 0;
}
