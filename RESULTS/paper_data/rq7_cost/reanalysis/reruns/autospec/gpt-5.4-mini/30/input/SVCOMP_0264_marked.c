#include <stdlib.h>

int f();

/* 1. FUNC CONTRACT */
int f() {

    int *i = (int *)malloc(sizeof(int) * (10));
int i_len = 10;
    return i[3] == 0;
}
