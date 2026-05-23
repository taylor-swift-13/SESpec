
#include <limits.h>

/*@
  logic integer gcd_logic(integer a, integer b) =
    b == 0 ? a : gcd_logic(b, a % b);
*/

/*@
  requires x > 0 && y > 0;
  assigns \nothing;
  ensures \result == (x * y) / gcd_logic(x, y);
  ensures \result > 0;
  ensures gcd_logic(\old(x), \old(y)) == gcd_logic(x, y);
*/
int foo322(int x, int y) {
    int gcd = 1;
    int foo322 = 1;
    if (x > y) {
        int temp = x;
        x = y;
        y = temp;
    }

    /*@
      loop invariant 1 <= i <= x + 1;
      loop invariant \forall integer k; 1 <= k < i ==> (x % k == 0 && y % k == 0 ==> gcd >= k);
      loop assigns gcd;
      loop variant x - i;
    */
    for (int i = 1; i <= x; i++) {
        if (x % i == 0 && y % i == 0) {
            gcd = i;
        }
    }

    foo322 = (x * y) / gcd;
    return foo322;
}
