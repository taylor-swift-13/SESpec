
/*@
  logic integer nb_divisors(integer x, integer n) =
    n <= 0 ? 0 : nb_divisors(x, n - 1) + (x % n == 0 ? 1 : 0);
*/

#include <limits.h>

int foo347(int x, int y) {

        if (y < 0) {
            y = -y;
        }
        int count = 0;
        
            
        /*@
          loop invariant 1 <= i <= y + 1;
          loop invariant 0 <= count <= i - 1;
          loop invariant count == nb_divisors(x, i - 1);
          loop invariant \forall integer k; 1 <= k < i ==> (x % k == 0 || x % k != 0);
          loop invariant y >= 0;
          loop invariant x == \at(x,Pre);
          loop invariant y == \at(y,Pre) || y == -\at(y,Pre);
          loop assigns i, count;
            */
            for (int i = 1; i <= y; i++) {
            if (x % i == 0) {
                count = count + 1;
            }
        }
            
        return count;
}
