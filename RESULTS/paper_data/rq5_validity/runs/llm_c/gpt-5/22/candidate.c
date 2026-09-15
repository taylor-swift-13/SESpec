#include <stdlib.h>

int func(int size);

/*@ 
  behavior negative:
    assumes size < 0;
    ensures \result == -1;

  behavior nonnegative:
    assumes size >= 0;
    ensures \result == 1;

  complete behaviors;
  disjoint behaviors;
*/
int func(int size) {

    if (size < 0) return -1;
    int *int_array = (int *)malloc(sizeof(int) * (size));
    int int_array_len = size;

    /*@ assert int_array_len == size; */
    if(int_array_len != size)
      return 0;
    return 1;
}
