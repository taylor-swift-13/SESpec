
int foo382(int n, int x, int y) {

        int max = 0;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= max;
          loop invariant max <= i;
          loop invariant max == 0 || (1 <= max && max <= \at(n,Pre));
          loop invariant max == 0 || ((max % x) == y);
          loop invariant \forall integer k; 1 <= k < i && ((k % x) == y) ==> k <= max;
          loop invariant \forall integer k; 1 <= k < i && ((k % x) == y) ==> k <= \at(n,Pre);
          loop invariant max == 0 || ((max % x) == y);
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
