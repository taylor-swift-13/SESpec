
/*@
  predicate is_divisor(integer n, integer d) = d != 0 && n % d == 0;
*/

int foo367(int n) {

        int i = 2;
        
        /* >>> LOOP INVARIANT TO FILL <<< */
        
        /*@
          loop invariant \true;
          loop invariant 2 <= i;
          loop invariant \forall integer j; 2 <= j < i ==> n % j != 0;
          loop assigns i;
        */
        while (i <= n / i) {
            if (n % i == 0) {
                return i;
            }
            i++;
        }
            
        return n;
}
