
/*@ 
  predicate common_divisor_upto(integer gx, integer gy, integer i, integer g) =
    (1 <= g && g <= i && gx % g == 0 && gy % g == 0);
@*/

int foo140(int x, int y) {

        int gcd = 1;
        int foo140 = 1;
        if (x > y) {
            int temp = x;
            x = y;
            y = temp;
        }
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= i;
          loop invariant 1 <= gcd;
          loop invariant x % gcd == 0 && y % gcd == 0;
          loop invariant gcd <= i;
          loop invariant foo140 == 1;
          loop assigns i, gcd;
            */
            for (int i = 1; i <= x; i++) {
            if (x % i == 0 && y % i == 0) {
                gcd = i;
            }
        }
            
        foo140 = (x * y) / gcd;
        return foo140;
}
