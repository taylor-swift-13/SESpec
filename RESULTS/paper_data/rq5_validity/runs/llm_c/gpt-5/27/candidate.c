#include <assert.h>

/*@ 
  requires args_len >= 0;
  requires args_len == 0 || \valid_read(args + (0 .. args_len-1));
  assigns \nothing;
*/
void main(const char **args, int args_len);

void main(const char **args, int args_len) {
    int i = 99;
    ++i;
    /*@ assert i == 100; */
    int tmp = i + 2; i = tmp;
    /*@ assert i == 102; */
    tmp = i - 3; i = tmp;
    /*@ assert i == 99; */
    i += 3; i -= 3;
    /*@ assert i == 99; */
    tmp = i * 2; i = tmp;
    /*@ assert i == 198; */
    tmp = i / 3; i = tmp;
    /*@ assert i == 66; */
    i %= 34; i = -i;
    /*@ assert i == -32; */
    assert(i == -32);

    long long l = 99;
    ++l; l += 2LL; l -= 3LL; l *= 2LL; l /= 3LL; l %= 34LL; l = -l;
    /*@ assert l == -32LL; */
    assert(l == -32LL);
}
