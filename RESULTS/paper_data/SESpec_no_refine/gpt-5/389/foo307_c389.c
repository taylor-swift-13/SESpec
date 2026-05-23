
/*@
logic integer pow10(integer e) = (e <= 0 ? 1 : 10 * pow10(e - 1));
*/

int foo307_c389(int p, int q, int n) {

        int res = 0;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (\at(n,Pre) > 0) ==> (0 <= \at(n,Pre) - n);
          loop invariant (!(\at(n,Pre) > 0)) ==> ((res == 0)&&(n == \at(n,Pre))&&(q == \at(q,Pre))&&(p == \at(p,Pre)));
          loop invariant q == \at(q,Pre);
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
