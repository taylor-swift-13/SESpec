#include <assert.h>

typedef enum { VAL5 = 5 } enum1;

void main(const char **args, int args_len);

void main(const char **args, int args_len) {
    enum1 e = VAL5;
    assert(e == VAL5);
}
