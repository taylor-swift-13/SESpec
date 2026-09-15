
/*@
predicate divides(integer a, integer b) = a != 0 && b % a == 0;
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
          loop invariant 1 <= i;
          loop invariant 1 <= gcd;
          loop invariant divides(gcd, x) && divides(gcd, y);
          loop invariant \forall integer k; 1 <= k < i && divides(k, x) && divides(k, y) ==> k <= gcd;
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
