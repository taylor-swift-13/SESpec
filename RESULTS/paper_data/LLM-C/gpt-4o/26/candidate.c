#include <assert.h>

/*@
    requires \valid_read(args+(0..args_len-1));
    ensures \result == 0;
*/
void main(const char **args, int args_len);

void main(const char **args, int args_len) {
    float f = 2.5f;
    //@ assert f == 2.5f;
    //@ assert f < 3.0f;
    //@ assert f > 2.0f;
    double d = 2.5;
    //@ assert d == 2.5;
    //@ assert d < 3.0;
    //@ assert d > 2.0;
}
