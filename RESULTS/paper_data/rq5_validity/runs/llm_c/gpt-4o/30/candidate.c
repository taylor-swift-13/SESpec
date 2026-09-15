#include <stdlib.h>

/*@
    ensures \result == 0 || \result == 1;
    allocates \result == 1 ? \nothing : \nothing;
*/
int f();

/*@
    ensures \result == 0 || \result == 1;
    allocates \result == 1 ? \nothing : \nothing;
*/
int f() {

    int *i = (int *)malloc(sizeof(int) * (10));
int i_len = 10;
    return i[3] == 0;
}
