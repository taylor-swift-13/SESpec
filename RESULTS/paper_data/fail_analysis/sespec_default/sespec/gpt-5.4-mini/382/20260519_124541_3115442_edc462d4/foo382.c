
/*@
  requires x != 0;
  requires 0 <= y && y < ((x > 0) ? x : -x);
  assigns \nothing;
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
