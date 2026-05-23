
/*@
  assigns \nothing;
  ensures \result == count_divisors(x, (y < 0 ? -y : y));
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
