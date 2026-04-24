#include <stdlib.h>

int f();

int f() {

    try {
      int *a = (int *)malloc(sizeof(int) * (-1));
int a_len = -1;
    } catch (Exception exc) {
      return 0;
    }
    return 1;
}
