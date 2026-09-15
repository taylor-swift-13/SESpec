
#include <stdlib.h>

/*@
  requires 0 <= size < 4;
  assigns \result;
  ensures \result == 1;
*/
int foo16(int size);

int foo16(int size) {
    if (size < 0) return -1;
    if (size < 0 || size >= 4) return 0;
    int a[4] = {0, 0, 0, 0};
    int i = a[size];
    (void)i;
    return 1;
}
