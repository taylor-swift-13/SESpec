
/*@ 
*/

/*@
predicate PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION = \true;
*/


int foo134(int x, int y) {

        int res = 0, m = x, n = y, sign = 1;
        if(x < 0){
            m = -x;
            sign = -sign;
        }
        if(y < 0){
            n = -y;
            sign = -sign;
        }
        
        /*@
          loop invariant 0 <= i <= m;
          loop invariant res == i * n;
          loop assigns res, i;
        */
        for(int i = 0; i < m; i++) {
            
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= j <= n;
          loop invariant res == i * n + j;
          loop assigns res, j;
            */
            for(int j = 0; j < n; j++) {
                res = res + 1;
            }
            
        }
            
        return sign * res;
}
