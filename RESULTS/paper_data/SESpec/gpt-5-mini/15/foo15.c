#include <stdlib.h>

int foo15(int size);


/*@
  requires \true;
  requires size < 0 || (0 <= size && size < 4);
  
  ensures size < 0 ==> \result == -1;
  ensures size >= 4 ==> \result == 0;
  ensures 0 <= size && size < 4 ==> \result == 1;
  ensures \result == -1 || \result == 0 || \result == 1;
*/
int foo15(int size) {
    if (size < 0) return -1;
    if (size < 0 || size >= 4) return 0;
    int *a = (int *)malloc(sizeof(int) * 4);
    a[size] = 0;
    return 1;
}