
/*@
  predicate is_sol(integer j, integer x, integer y) =
    j > 0 && (x != 0 ==> j % x == y);
*/

int foo382(int n, int x, int y) {

        int max = 0;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant max == 0
                        || (1 <= max <= i - 1 && is_sol(max, x, y));
          loop assigns i, max;
            */
            for (int i = 1; i <= n; i++) {
            if ((i % x) == y) {
                max = i;
            }
        }
            
        return max;
}
