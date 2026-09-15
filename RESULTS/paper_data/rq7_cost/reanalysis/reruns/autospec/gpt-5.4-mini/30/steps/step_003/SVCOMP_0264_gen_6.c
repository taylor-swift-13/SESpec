#include <stdlib.h>

int f();

/*@
requires \valid(((int *)malloc(sizeof(int) * (10))) + (0..9));
assigns \nothing;
ensures \result == 1 || \result == 0;
*/
int f() {

    int *i = (int *)malloc(sizeof(int) * (10));
int i_len = 10;
    return i[3] == 0;
}
