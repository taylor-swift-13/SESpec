#include <stdlib.h>

int foo16(int size);


/*@
  ensures size < 0 ==> \result == -1;
  ensures size >= 0 && size >= 4 ==> \result == 0;
  ensures size >= 0 && size < 4 ==> \result == 1;
  assigns \nothing;
*/
int foo16(int size) {
    if (size < 0) return -1;
    if (size < 0 || size >= 4) return 0;
    return 1;
}