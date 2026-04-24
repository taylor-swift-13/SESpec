#include <stdlib.h>

int func(int size);

int func(int size) {

    if (size < 0) return -1;
    int *int_array = (int *)malloc(sizeof(int) * (size));
int int_array_len = size;

    if(int_array_len != size)
      return 0;
    return 1;
}
