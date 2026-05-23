
#include <limits.h>

/*@
  logic integer gcd_logic(integer a, integer b) =
    b == 0 ? a : gcd_logic(b, a % b);
*/

/*@
  requires x > 0 && y > 0;
  ensures \result == (x * y) / gcd_logic(x, y);
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
      loop invariant gcd_logic(x, y) == gcd_logic(x, y);
      loop invariant foo322 == 1;
      loop invariant y == \at(x,Pre) || y == \at(y,Pre);
      loop invariant x == \at(y,Pre) || x == \at(x,Pre);
      loop assigns i, gcd;
    */
    for (int i = 1; i <= x; i++) {
        if (x % i == 0 && y % i == 0) {
            gcd = i;
        }
    }

    foo322 = (x * y) / gcd;
    return foo322;
}
