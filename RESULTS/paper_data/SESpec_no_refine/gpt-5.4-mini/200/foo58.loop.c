
/*@
PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
*/

/*@
PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
*/


int foo58(int x, int y) {

        int res = 0, m = x, n = y, sign = 1;
        if(x < 0){
            m = -x;
            sign = -sign;
        }
        if(y < 0){
            n = -y;
            sign = -sign;
        }
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= i <= m;
          loop invariant sign == 1 || sign == -1;
          loop invariant m == (x < 0 ? -x : x);
          loop invariant n == (y < 0 ? -y : y);
          loop invariant res == i * n;
          loop assigns i, j, res;
            */
            for(int i = 0; i < m; i++) {
            
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant 0 <= j <= n;
              loop invariant res == i * n + j;
              loop assigns j, res;
            */
            for(int j = 0; j < n; j++) {
                res = res + 1;
            }
            
        }
            
        return sign * res;
}
