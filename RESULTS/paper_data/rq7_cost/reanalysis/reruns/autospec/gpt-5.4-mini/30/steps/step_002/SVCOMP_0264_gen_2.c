#include <stdlib.h>

int f();

/*@
assigns \nothing;
requires \valid((int *)i + (0..9));
*/
int f() {

    int *i = (int *)malloc(sizeof(int) * (10));
int i_len = 10;
    return i[3] == 0;
}
