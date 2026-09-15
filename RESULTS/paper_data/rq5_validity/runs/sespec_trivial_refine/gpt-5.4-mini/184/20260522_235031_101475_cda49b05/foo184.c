
#include <stdlib.h>
#include <limits.h>

/*@
  requires 1 <= n;
  requires n <= INT_MAX - 1;
  assigns \result \from n;
  ensures \result >= 0;
*/
int foo184(int n) {
    (void)n;
    return 0;
}
