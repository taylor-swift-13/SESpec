#include <stdlib.h>

/*@
    requires size >= 0;
    ensures \result == -1 ==> size < 0;
    ensures \result == 0 ==> size >= 0 && \valid(int_array+(0..size-1)) && int_array_len != size;
    ensures \result == 1 ==> size >= 0 && \valid(int_array+(0..size-1)) && int_array_len == size;
    assigns \nothing;
*/
int func(int size);

int func(int size) {

    if (size < 0) return -1;
    int *int_array = (int *)malloc(sizeof(int) * (size));
    int int_array_len = size;

    if(int_array_len != size)
      return 0;
    return 1;
}
