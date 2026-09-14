#include <stdlib.h>

int foo16(int size);

int foo16(int size) {
    if (size < 0) return -1;
    if (size < 0 || size >= 4) return 0;
    int *a = (int *)malloc(sizeof(int) * 4);
    int i = a[size];
    (void)i;
    return 1;
}
