#include <assert.h>

typedef enum { VAL5 = 5 } enum1;

void foo25(const char **args, int args_len);


/*@
  assigns \nothing;
*/
void foo25(const char **args, int args_len) {
    enum1 e = VAL5;
    assert(e == VAL5);
}