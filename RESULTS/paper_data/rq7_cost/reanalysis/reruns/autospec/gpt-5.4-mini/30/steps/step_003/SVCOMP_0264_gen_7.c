#include <stdlib.h>

int f();

/*@
requires \valid((int *)i + (0..9));
requires \initialized((int *)i + (0..9));
assigns \nothing;
ensures \result == (i[3] == 0);
*/
int f() {

    int *i = (int *)malloc(sizeof(int) * (10));
int i_len = 10;
    return i[3] == 0;
}
