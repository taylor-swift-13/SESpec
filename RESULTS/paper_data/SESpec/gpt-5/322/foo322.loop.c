
/* No extra predicates or logic functions are needed for this loop. */

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
          // Basic bounds valid at entry and preserved
          loop invariant 1 <= i;
          loop invariant gcd >= 1;
          // After the optional swap, x <= y is stable
          loop invariant x <= y;
          // gcd divides both x and y at all times
          loop invariant (x % gcd == 0) && (y % gcd == 0);
          // For all processed candidates, gcd is at least as large as any common divisor seen
          loop invariant \forall integer d; 1 <= d < i ==> ((x % d == 0 && y % d == 0) ==> d <= gcd);
          // If a common divisor >= 2 has been seen, gcd reflects that (non-triviality)
          loop invariant (\exists integer d; 2 <= d < i && x % d == 0 && y % d == 0) ==> (gcd >= 2);
          // No unprocessed index can affect gcd before being examined
          loop invariant \forall integer d; i <= d <= x ==> ((x % d == 0 && y % d == 0) ==> gcd <= d || gcd == 1);
          // Template-compatible scaffolding without relying on old-state equalities
          loop invariant (i <= \at(y,Pre)) ==> (gcd >= 1);
          loop invariant (i <= \at(y,Pre)) ==> ((foo322 == 1) && (gcd >= 1));
          loop invariant (!(i <= \at(y,Pre))) ==> (foo322 == 1);
          loop invariant foo322 == 1;
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
