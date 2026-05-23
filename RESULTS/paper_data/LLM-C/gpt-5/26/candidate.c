#include <assert.h>

/*@ 
  requires args_len >= 0;
  requires args_len == 0 || \valid_read(args + (0 .. args_len-1));
  assigns \nothing;
*/
void main(const char **args, int args_len);

/*@ 
  requires args_len >= 0;
  requires args_len == 0 || \valid_read(args + (0 .. args_len-1));
  assigns \nothing;
*/
void main(const char **args, int args_len) {
    float f = 2.5f;
    /*@ assert f == 2.5f; */
    assert(f == 2.5f);
    /*@ assert f < 3.0f; */
    assert(f < 3.0f);
    /*@ assert f > 2.0f; */
    assert(f > 2.0f);
    double d = 2.5;
    /*@ assert d == 2.5; */
    assert(d == 2.5);
    /*@ assert d < 3.0; */
    assert(d < 3.0);
    /*@ assert d > 2.0; */
    assert(d > 2.0);
}
