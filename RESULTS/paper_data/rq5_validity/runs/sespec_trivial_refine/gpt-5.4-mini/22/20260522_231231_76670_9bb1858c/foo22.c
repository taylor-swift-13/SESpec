
#include <stdlib.h>

/*@
  requires 0 <= size;
  assigns \nothing;
  ensures \result == 1;
*/
int foo22(int size);

/*@
  requires 0 <= size;
  assigns \nothing;
  ensures \result == 1;
*/
int foo22(int size) {
  return 1;
}
