
#include <limits.h>

/*@
  predicate lower_bound{L}(int *a, integer n, integer m) =
    \forall integer k; 0 <= k < n ==> m <= a[k];
*/

/*@
  requires a_len >= 0;
  requires a_len == 0 || \valid_read(a + (0 .. a_len-1));
  assigns \nothing;
  ensures a_len == 0 ==> \result == -1;
  ensures a_len > 0 ==> \forall integer k; 0 <= k < a_len ==> \result <= a[k];
  ensures a_len > 0 ==> (\exists integer k; 0 <= k < a_len && a[k] == \result);
*/
int foo132(int *a, int a_len) {
  if (a_len == 0) return -1;

  int res = a[0];

  /*@
    loop invariant 1 <= i <= a_len;
    loop invariant \forall integer k; 0 <= k < i ==> res <= a[k];
    loop invariant \exists integer k; 0 <= k < i && a[k] == res;
    loop assigns i, res;
    loop variant a_len - i;
  */
  for (int i = 1; i < a_len; i++) {
    if (a[i] < res) {
      res = a[i];
    }
  }

  return res;
}
