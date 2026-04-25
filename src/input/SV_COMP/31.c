#include <stdlib.h>

int foo31();

int foo31() {

    try {
      int *a = (int *)malloc(sizeof(int) * (-1));
int a_len = -1;
    } catch (Exception exc) {
      return 0;
    }
    return 1;
}
