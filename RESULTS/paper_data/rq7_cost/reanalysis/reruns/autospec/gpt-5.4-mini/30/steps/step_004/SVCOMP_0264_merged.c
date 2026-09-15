#include <stdlib.h>

int f();

/*@
requires \valid(((int*)0) + (0..9));
requires \true;
ensures \result == 0 || \result == 1;
assigns \nothing;
*/
int f() {

    int *i = (int *)malloc(sizeof(int) * (10));
int i_len = 10;
    return i[3] == 0;
}
