#include <assert.h>

void foo49_c27(const char **args, int args_len);


void foo49_c27(const char **args, int args_len) {
    int i = 99;
    ++i;
    int tmp = i + 2; i = tmp;
    tmp = i - 3; i = tmp;
    i += 3; i -= 3;
    tmp = i * 2; i = tmp;
    tmp = i / 3; i = tmp;
    i %= 34; i = -i;
    assert(i == -32);
    long long l = 99;
    ++l; l += 2LL; l -= 3LL; l *= 2LL; l /= 3LL; l %= 34LL; l = -l;
    assert(l == -32LL);
}