#include <stddef.h>
#include <stdlib.h>

int foo6(int unknown);

int foo6(int unknown) {

    int *arr = NULL;
int arr_len = 0;
    if (unknown > 0)
      arr = (int *)malloc(sizeof(int) * (1)); arr_len = 1;
    else
      arr = (int *)malloc(sizeof(int) * (0)); arr_len = 0;

    if (unknown > 0)
      arr[0] = 1;

    if (unknown > 0)
      return arr_len == 1 && arr[0] == 1;
    else
      return arr_len == 0;
}
