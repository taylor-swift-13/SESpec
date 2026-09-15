
/*@
  predicate divides(integer n, integer d) = (d != 0) && (n % d == 0);
*/

int foo323(int n) {

        int count = 0;
        if (n == 1) return 1;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 2 <= i;
          loop invariant count >= 0;
          loop invariant count <= i - 2;
          loop invariant \forall integer d; 2 <= d < i ==> (divides(n,d) <==> (n % d == 0));
          loop invariant \forall integer d; 2 <= d < i ==> (divides(n,d) ==> (n / d != d));
          loop invariant (i <= n / i) ==> (2 <= i);
          loop assigns i, count;
            */
            for (int i = 2; i <= n / i; i++) {
            if (n % i == 0) {
                count++;
                if (n / i == i) {
                    break;
                }
            }
        }
            
        return count;
}
