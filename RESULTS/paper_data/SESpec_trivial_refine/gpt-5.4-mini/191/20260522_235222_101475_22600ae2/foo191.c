
#include <stdlib.h>

        /*@
  requires count >= 1;
  assigns \result \from count;
  ensures count % 2 == 1 ==> \result == 0;
  ensures count % 2 == 0 ==> \result > 0;
  ensures \result >= 0;
  ensures \result == 0 <==> count % 2 == 1;
*/
int foo191(int count) {
  return (count % 2 == 0) ? 1 : 0;
}
