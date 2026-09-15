
/*@
  assigns \nothing;
  // Result is 0 exactly when the input is <= 1
  // For inputs >= 2, the result is at least 2
*/
int foo346(int n) {

        int max = 0;
        
        /* >>> LOOP INVARIANT TO FILL <<< */
        /*@
          loop invariant 2 <= i;
          loop invariant (i <= \at(n,Pre)) ==> (n >= 1);
          loop assigns i, max, n;
        */
        for (int i = 2; i <= n; i++) {
            /* >>> LOOP INVARIANT TO FILL <<< */
            /*@
              loop invariant n >= 0;
              loop invariant i >= 2;
              loop assigns max, n;
            */
            while (n % i == 0) {
                max = i;
                n /= i;
            }
        }
            
        return max;
}
