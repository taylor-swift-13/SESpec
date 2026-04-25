#include <stdlib.h>

int foo7(int size);

int foo7(int size) {

    if (size < 0)
      return -1;
    try {
      int *a = (int *)malloc(sizeof(int) * (4));
int a_len = 4;
      a[size] = 0;
    } catch (ArrayIndexOutOfBoundsException exc) {
      return 0;
    }
    return 1;
}
