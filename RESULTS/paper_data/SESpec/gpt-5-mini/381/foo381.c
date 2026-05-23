
/*@ 
  logic integer common_prefix{L}(integer x, integer y, integer n) =
    n <= 0 ? 0 : common_prefix{L}(x, y, n-1) + ((x % n == 0 && y % n == 0) ? 1 : 0);
*/

 /*@
  requires x >= 0 && y >= 0 && (x != 0 || y != 0);
  assigns \nothing;
  ensures \result >= 0;
*/
int foo381(int x, int y) {

        int count = 0;
        
        /*@
          loop invariant 1 <= i;
          loop invariant 0 <= count;
          loop invariant count <= i-1;
          loop invariant x == \at(x,Pre) && y == \at(y,Pre);
          loop assigns i, count;
        */
        for (int i = 1; i <= x && i <= y; i++) {
            if (x % i == 0 && y % i == 0) {
                count++;
            }
        }
            
        return count;
}
