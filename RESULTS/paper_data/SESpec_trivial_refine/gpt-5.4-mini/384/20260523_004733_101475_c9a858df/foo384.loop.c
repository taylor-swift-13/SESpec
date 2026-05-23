
/*@
logic integer comb_step(integer n, integer i) =
  i <= 0 ? 1 : comb_step(n, i - 1) * (n - i + 1) / i;
*/
        
int foo384(int n, int k) {

        if (k > n - k)
            k = n - k;
        int c = 1;
        
        /*@ 
          loop invariant 1 <= i <= k + 1;
          loop invariant c == comb_step(n, i - 1);
          loop assigns i, c;
        */
            /*@
          loop invariant 1 <= i <= k + 1;
          loop invariant c == comb_step(n, i - 1);
          loop assigns i, c;
            */
            for (int i = 1; i <= k; i++) {
            c = c * (n - i + 1) / i;
        }
            
        return c;
}
