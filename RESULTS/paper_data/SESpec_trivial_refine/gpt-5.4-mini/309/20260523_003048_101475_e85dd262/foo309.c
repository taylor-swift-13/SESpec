
#include <limits.h>

        /*@
        predicate max_pos_prefix{L}(int *positions, integer n, integer m) =
          \forall integer k; 0 <= k < n ==> positions[k] <= 0 || positions[k] <= m;
        */

/*@
  requires 0 <= positions_len;
  requires positions_len == 0 || \valid_read(positions + (0 .. positions_len-1));
  assigns \nothing;
  ensures \result >= 0;
  ensures \forall integer k; 0 <= k < positions_len ==> \result >= positions[k] || positions[k] <= 0;
  ensures \result == 0 ==> (\forall integer k; 0 <= k < positions_len ==> positions[k] <= 0);
*/
int foo309(int *positions, int positions_len) {
  int largest = 0;

  /*@
    loop invariant 0 <= index <= positions_len;
    loop invariant largest >= 0;
    loop invariant \forall integer k; 0 <= k < index && positions[k] > 0 ==> positions[k] <= largest;
    loop invariant largest == 0 ==> (\forall integer k; 0 <= k < index ==> positions[k] <= 0);
    loop assigns index, largest;
    loop variant positions_len - index;
  */
  for (int index = 0; index < positions_len; index++) {
    if (positions[index] > 0 && positions[index] > largest) {
      largest = positions[index];
    }
  }

  return largest;
}
