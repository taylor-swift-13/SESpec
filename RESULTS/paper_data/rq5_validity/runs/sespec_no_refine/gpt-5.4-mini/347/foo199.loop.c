
/*@ 
  logic integer count_divisors(integer x, integer y) = 
    y <= 0 ? 0 : (x % y == 0 ? 1 : 0) + count_divisors(x, y - 1);
*/

int foo199(int x, int y) {

        if (y < 0) {
            y = -y;
        }
        int count = 0;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant x == \at(x,Pre);
          loop assigns i, count;
            */
            for (int i = 1; i <= y; i++) {
            if (x % i == 0) {
                count = count + 1;
            }
        }
            
        return count;
}
