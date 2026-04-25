#include <stdlib.h>

int foo9(int index);

int foo9(int index) {

    try {
      int *a = (int *)malloc(sizeof(int) * (4));
int a_len = 4;
      a[index] = 0;
    } catch (Exception exc) {
      return 0;
    }
    return 1;
}
