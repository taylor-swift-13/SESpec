#include <assert.h>

typedef enum { VAL5 = 5 } enum1;

/*@
    requires args_len >= 0;
    assigns \nothing;
*/
void main(const char **args, int args_len);

void main(const char **args, int args_len) {
    enum1 e = VAL5;
    assert(e == VAL5);
}
