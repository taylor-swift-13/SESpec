
/*@
  // No additional predicates or logic functions are needed.
*/

int foo367(int n) {

        int i = 2;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant n == n;
          loop invariant i >= 2;
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
