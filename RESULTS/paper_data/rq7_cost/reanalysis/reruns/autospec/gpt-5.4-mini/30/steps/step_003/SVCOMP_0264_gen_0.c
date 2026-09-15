#include <stdlib.h>

int f();

/*@
requires \true;
ensures \result == (i[3] == 0);
assigns \nothing;
*/
int f() {

    int *i = (int *)malloc(sizeof(int) * (10));
int i_len = 10;
    return i[3] == 0;
}
