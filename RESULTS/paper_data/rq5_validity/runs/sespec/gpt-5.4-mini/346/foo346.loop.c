
/*@
predicate divides(integer a, integer b) = a != 0 && b % a == 0;
*/

int foo346(int n) {

        int max = 0;
        
        /*@
          loop invariant 2 <= i;
          loop invariant max == 0 || max >= 2;
          loop invariant max <= i;
          loop assigns i, max, n;
        */
            for (int i = 2; i <= n; i++) {
            
            
        /*@
          loop invariant i >= 2;
          loop invariant max == 0 || max >= 2;
          loop invariant max <= i;
          loop assigns max, n;
        */
            while (n % i == 0) {
                max = i;
                n /= i;
            }
            
        }
            
        return max;
}
