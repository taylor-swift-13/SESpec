#include <stdlib.h>

int f();

/*@
assigns \nothing;
requires \valid(((int *)malloc(sizeof(int) * (10)))+(0..9));
ensures \result == 0 || \result == 1;
*/
int f() {

    int *i = (int *)malloc(sizeof(int) * (10));
int i_len = 10;
    return i[3] == 0;
}
