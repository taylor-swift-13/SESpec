#include <stdlib.h>

int foo15(int size);


/*@
  
  ensures (\result == -1) <==> (size < 0);
  ensures (\result == 0) <==> (size >= 4);
  ensures (\result == 1) <==> (0 <= size && size < 4);
  ensures \result == -1 || \result == 0 || \result == 1;
  ensures size >= 0 ==> \result >= 0;
  ensures size < 0 ==> \result < 0;
*/
int foo15(int size) {
    if (size < 0) return -1;
    if (size < 0 || size >= 4) return 0;
    int *a = (int *)malloc(sizeof(int) * 4);
    a[size] = 0;
    return 1;
}