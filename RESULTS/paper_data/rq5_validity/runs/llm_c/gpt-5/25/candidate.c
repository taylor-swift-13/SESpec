#include <assert.h>

typedef enum { VAL5 = 5 } enum1;

/*@ 
  requires \valid_read(args + (0 .. args_len-1));
  requires args_len >= 0;
  assigns \nothing;
*/
void main(const char **args, int args_len);

/*@ 
  requires \valid_read(args + (0 .. args_len-1));
  requires args_len >= 0;
  assigns \nothing;
*/
void main(const char **args, int args_len) {
    enum1 e = VAL5;
    /*@ assert e == VAL5; */
    assert(e == VAL5);
}
