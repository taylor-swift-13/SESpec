#include <stdlib.h>

int foo8(int size);

int foo8(int size) {

    if (size < 0) return -1;
    try {
      int *a = (int *)malloc(sizeof(int) * (4));
int a_len = 4;
      int i = a[size];
    } catch (ArrayIndexOutOfBoundsException exc) {
      return 0;
    }
    return 1;
}
