
/*@
  logic integer min2(integer a, integer b) = a <= b ? a : b;
*/
/*@
  assigns \nothing;
  ensures (\result == 0) <==> (x <= 0 || y <= 0);
  ensures (x > 0 && y > 0) ==> (\result == common_div_count(x, y, min2(x, y)));
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
