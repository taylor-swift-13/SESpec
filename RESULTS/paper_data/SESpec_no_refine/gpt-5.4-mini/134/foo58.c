
/*@
PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
*/

/*@
logic integer abs_int(integer v) = v < 0 ? -v : v;
*/
/*@ logic integer foo58_res(integer x, integer y) = abs_int(x) * abs_int(y); */

int foo58(int x, int y) {
        /*@
          assigns \nothing;
          ensures \result == foo58_res(x, y);
        */
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
          loop invariant m == \at(x,Pre) || m == -\at(x,Pre);
          loop invariant n == \at(y,Pre) || n == -\at(y,Pre);
          loop invariant sign == 1 || sign == -1;
          loop invariant res == i * n;
          loop assigns i, res, j;
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
