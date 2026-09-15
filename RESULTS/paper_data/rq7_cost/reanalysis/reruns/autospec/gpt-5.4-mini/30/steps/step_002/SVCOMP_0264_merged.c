#include <stdlib.h>

int f();

/*@
requires \valid_read((int *)i + (0..9));
requires \valid(i + (0..i_len-1));
requires \valid((int *)i + (0..9));
requires \valid((int *)(i + (0..9)));
requires \valid(((int *)malloc(sizeof(int) * (10)))+(0..9));
requires \true;
ensures \result == 0 || \result == 1;
ensures \result == (i[3] == 0);
assigns \nothing;
*/
int f() {

    int *i = (int *)malloc(sizeof(int) * (10));
int i_len = 10;
    return i[3] == 0;
}
