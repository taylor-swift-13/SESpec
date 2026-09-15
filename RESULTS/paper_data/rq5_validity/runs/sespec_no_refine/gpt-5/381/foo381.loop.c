
/*@
  // Logical indicator: 1 if d divides n, 0 otherwise
  logic integer divides(integer n, integer d) = (d != 0 && n % d == 0) ? 1 : 0;

  // Count of common divisors of x and y in the range [1..k]
  logic integer common_div_count(integer x, integer y, integer k) =
    (k <= 0) ? 0 : common_div_count(x, y, k - 1) + ((divides(x, k) == 1 && divides(y, k) == 1) ? 1 : 0);
*/

int foo381(int x, int y) {

        int count = 0;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant y == \at(y,Pre);
          loop invariant x == \at(x,Pre);
          loop assigns i, count;
            */
            for (int i = 1; i <= x && i <= y; i++) {
            if (x % i == 0 && y % i == 0) {
                count++;
            }
        }
            
        return count;
}
