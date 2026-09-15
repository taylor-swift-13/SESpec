
/*@
*/

/*@
  assigns \nothing;
  ensures (\old(n) <= 1 ==> \result == 0)
          &&
          (\old(n) >= 2 ==> (\result >= 2
                              && \old(n) % \result == 0
                              && (\forall integer d; d > \result && d <= \old(n) ==> \old(n) % d != 0)));
*/
int foo346(int n) {

        int max = 0;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant max >= 0;
              loop invariant n >= 0;
              loop assigns i, max, n;
            */
            for (int i = 2; i <= n; i++) {
            
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant i >= 2;
              loop invariant 0 <= max <= i;
              loop invariant \forall integer d; 2 <= d < i ==> n % d != 0;
              loop assigns n, max;
            */
            while (n % i == 0) {
                max = i;
                n /= i;
            }
            
        }
            
        return max;
}
