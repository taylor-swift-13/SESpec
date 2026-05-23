
        /*@
        predicate is_match(integer j, integer x, integer y) = (j % x) == y;
        */
        
int foo382(int n, int x, int y) {

        int max = 0;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant max < i;
          loop invariant max == 0 || is_match(max, x, y);
          loop invariant \forall integer k; 1 <= k < i ==> (is_match(k, x, y) ==> k <= max);
          loop assigns i, max;
            */
            for (int i = 1; i <= n; i++) {
            if ((i % x) == y) {
                max = i;
            }
        }
            
        return max;
}
