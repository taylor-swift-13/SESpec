#include <stdlib.h>

/*@
    assigns \nothing;
    ensures \result == ( (\valid_read((int *)\at(i,Pre) + 3)) ? (((int *)\at(i,Pre))[3] == 0) : \result );
*/
int f();

int f() {

    int *i = (int *)malloc(sizeof(int) * (10));
int i_len = 10;
    return i[3] == 0;
}