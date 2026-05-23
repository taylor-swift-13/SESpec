#include <stdlib.h>

int foo7_c15(int size);


int foo7_c15(int size) {
    if (size < 0) return -1;
    if (size < 0 || size >= 4) return 0;
    int *a = (int *)malloc(sizeof(int) * 4);
    a[size] = 0;
    return 1;
}