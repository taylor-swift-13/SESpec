
/*@
  logic integer common_divisor_count(integer x, integer y, integer n) =
    n <= 0 ? 0 :
    common_divisor_count(x, y, n - 1) +
      ((x % n == 0 && y % n == 0) ? 1 : 0);
*/

int foo381(int x, int y) {

        int count = 0;
        
            
        /*@
          loop invariant 1 <= i;
          loop invariant count >= 0;
          loop invariant count <= i - 1;
          loop invariant count == common_divisor_count(\at(x,Pre), \at(y,Pre), i - 1);
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
