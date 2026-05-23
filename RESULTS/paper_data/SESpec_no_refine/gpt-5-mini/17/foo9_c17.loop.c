#include <stdlib.h>

int foo9_c17(int index);


int foo9_c17(int index) {
    if (index < 0 || index >= 4) return 0;
    int *a = (int *)malloc(sizeof(int) * 4);
    a[index] = 0;
    return 1;
}