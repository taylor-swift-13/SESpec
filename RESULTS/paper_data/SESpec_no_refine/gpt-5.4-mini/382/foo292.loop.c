
/*@ predicate PLACE_HOLDER_max(int max, int i, int n) = max == i; */

int foo292(int n, int x, int y) {

        int max = 0;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
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
