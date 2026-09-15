
#include <limits.h>
#include <stdlib.h>

/*@
logic integer prefix_sum{L}(int *a, integer l, integer u) =
  (l >= u ? 0 : a[l] + prefix_sum{L}(a, l + 1, u));
*/

/*@
  requires 0 <= seed <= INT_MAX - 1;
  assigns \result \from seed;
  ensures \result >= 1;
*/
int foo228(int seed) {
  (void)seed;
  return 1;
}
