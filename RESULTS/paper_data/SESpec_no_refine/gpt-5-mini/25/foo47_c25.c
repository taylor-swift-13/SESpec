#include <assert.h>

typedef enum { VAL5 = 5 } enum1;

void foo47_c25(const char **args, int args_len);


void foo47_c25(const char **args, int args_len) {
    enum1 e = VAL5;
    assert(e == VAL5);
}