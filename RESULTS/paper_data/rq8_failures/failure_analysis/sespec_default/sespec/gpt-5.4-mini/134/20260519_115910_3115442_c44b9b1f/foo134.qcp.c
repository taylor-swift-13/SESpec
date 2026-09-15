#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo134(int x, int y);

int foo134(int x, int y) 
/*@

Require emp
Ensure Results(__return)
*/{

        int res = 0, m = x, n = y, sign = 1;
        if(x < 0){
            m = -x;
            sign = -sign;
        }
        if(y < 0){
            n = -y;
            sign = -sign;
        }
       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (sign == -1 || sign == 1) &&
(x == x@pre) &&
(y == y@pre
          loop assigns i, res)
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