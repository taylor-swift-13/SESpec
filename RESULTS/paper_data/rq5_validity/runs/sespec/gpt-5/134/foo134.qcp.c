#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
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
       
  /*@ Inv
    (0 <= i && i <= m) &&
    (0 <= m) &&
    (0 <= n) &&
    (res == i * n) &&
    ((i < m) => (res >= 0)) &&
    ((i == m) => (res == m * n)) &&
    ((n == 0) => (res == 0)) &&
    ((m == 0) => (res == 0)) &&
    ((i < -x@pre) => (res == i * n)) &&
    (y == y@pre) &&
    (x == x@pre)
    */
for(int i = 0; i < m; i++) {
            
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= j <= n;
          loop invariant res == i * n + j;
          loop assigns res, j;
            */
            /*@ Inv
    (0 <= j && j <= n) &&
    (res == i * n + j)
    */
for(int j = 0; j < n; j++) {
                res = res + 1;
            }
            
        }
        return sign * res;
}