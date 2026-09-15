
/*@
  
  assigns \nothing;
*/
int foo384(int n, int k) {

        if (k > n - k)
            k = n - k;
        int c = 1;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= i;
          loop invariant n == \at(n,Pre);
          loop assigns i, c;
            */
            for (int i = 1; i <= k; i++) {
            c = c * (n - i + 1) / i;
        }
            
        return c;
}
