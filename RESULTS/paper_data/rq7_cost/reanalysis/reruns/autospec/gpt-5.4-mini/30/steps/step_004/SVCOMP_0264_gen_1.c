#include <stdlib.h>

int f();

/*@
ensures \result == 0 || \result == 1;
assigns \nothing;
*/
int f() {

    int *i = (int *)malloc(sizeof(int) * (10));
int i_len = 10;
    return i[3] == 0;
}
