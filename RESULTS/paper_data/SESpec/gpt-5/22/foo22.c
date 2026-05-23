#include <stdlib.h>

int foo22(int size);


/*@
  ensures (size < 0) ==> \result == -1;
  ensures (size >= 0) ==> \result == 1;
  ensures (\result == -1) <==> (size < 0);
  ensures (\result == 1) <==> (size >= 0);
  ensures \result == -1 || \result == 1;
*/
int foo22(int size) {

    if (size < 0) return -1;
    int *int_array = (int *)malloc(sizeof(int) * (size));
    int int_array_len = size;

    if(int_array_len != size)
      return 0;
    return 1;
}