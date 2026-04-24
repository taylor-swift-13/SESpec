#include <stdlib.h>

int f();

int f() {

    int *i = (int *)malloc(sizeof(int) * (10));
int i_len = 10;
    return i[3] == 0;
}
