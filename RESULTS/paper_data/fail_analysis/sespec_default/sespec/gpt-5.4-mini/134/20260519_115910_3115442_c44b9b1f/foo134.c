
/*@
PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
*/

/*@
PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
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
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant sign == -1 || sign == 1;
          
          loop invariant x == \at(x,Pre);
          loop invariant y == \at(y,Pre);
          loop assigns i, res;
            */
            for(int i = 0; i < m; i++) {
            
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop assigns i, res;
              loop variant m - i;
            */
            for(int j = 0; j < n; j++) {
                res = res + 1;
            }
            
        }
            
        return sign * res;
}
