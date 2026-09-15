#include <stdlib.h>

int f();

/*@
requires \valid(i + (0..i_len-1));
assigns \nothing;
ensures \result == (i[3] == 0);
*/
int f() {

    int *i = (int *)malloc(sizeof(int) * (10));
int i_len = 10;
    return i[3] == 0;
}
