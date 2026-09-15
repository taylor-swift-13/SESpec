
/*@
  // Helper predicate capturing that `g` is a common divisor of x and y.
  predicate is_common_divisor(integer x, integer y, integer g) =
    g >= 1 && x % g == 0 && y % g == 0;
*/

int foo322(int x, int y) {

        int gcd = 1;
        int foo322 = 1;
        if (x > y) {
            int temp = x;
            x = y;
            y = temp;
        }
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant foo322 == 1;
          loop invariant \forall integer d; 1 <= d < i ==> (d <= x && d <= y && x % d == 0 && y % d == 0) ==> gcd >= d;
          loop assigns i, gcd;
            */
            for (int i = 1; i <= x; i++) {
            if (x % i == 0 && y % i == 0) {
                gcd = i;
            }
        }
            
        foo322 = (x * y) / gcd;
        return foo322;
}
