
/*@ 
  assigns \nothing;
  
*/
int foo389(int p, int q, int n) {

        int res = 0;
        
        /*@
          loop invariant n <= \at(n,Pre);
          loop invariant q == \at(q,Pre);
          loop invariant (\at(n,Pre) <= 0) ==> ((res == 0) && (n == \at(n,Pre)) && (q == \at(q,Pre)) && (p == \at(p,Pre)));
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
