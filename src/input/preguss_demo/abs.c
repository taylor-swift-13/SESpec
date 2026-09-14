#include <limits.h>

int abs_int(int x);

int abs_int(int x) {
    if (x < 0) return -x;
    return x;
}
