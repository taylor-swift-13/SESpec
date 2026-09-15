
/*@
  requires q != 0;
  requires n >= 0;
*/

int foo389(int p, int q, int n) {

        int res = 0;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant n >= 0;
          loop invariant q != 0;
          loop assigns n, p, res;
            */
            while (n > 0) {
            n -= 1;
            p *= 10;
            res = p / q;
            p %= q;
        }
            
        return res;
}
