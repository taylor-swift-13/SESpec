
/*@
  logic boolean PLACE_HOLDER_VERFICATION_GOAL(integer i, integer n, integer x, integer y, integer max) =
    (max == 0) || (max <= i);

  logic boolean PLACE_HOLDER_max(integer i, integer n, integer x, integer y, integer max) =
    (max == 0) || (max <= i);
*/

int foo382(int n, int x, int y) {

        int max = 0;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant max == 0 || max < i;
          loop invariant y == \at(y,Pre);
          loop invariant x == \at(x,Pre);
          loop invariant n == \at(n,Pre);
          loop assigns i, max;
            */
            for (int i = 1; i <= n; i++) {
            if ((i % x) == y) {
                max = i;
            }
        }
            
        return max;
}
