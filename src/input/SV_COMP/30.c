#include <stdlib.h>

int foo30();

int foo30() {

    try {
      int *a = (int *)malloc(sizeof(int) * (-1));
int a_len = -1;
    } catch (NegativeArraySizeException exc) {
      return 0;
    }
    return 1;
}
