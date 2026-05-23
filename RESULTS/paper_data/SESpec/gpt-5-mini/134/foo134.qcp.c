#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
/*@ Extern Coq (non_negative : Z -> Prop) */

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
       
  /*0*/ 
 /*@ Inv
    (0 <= i && i <= m) &&
    (non_negative(n)) &&
    (res == i * n) &&
    (forall (k:Z), 0 <= k && k < i => res >= k * n) &&
    ((i == m) => (res == m * n)) &&
    (m == (x@pre < 0 ? -x@pre : x@pre)) &&
    (n == (y@pre < 0 ? -y@pre : y@pre))
    */
for(int i = 0; i < m; i++) {
           
  /*1*/ 
 /*@ Inv
    (0 <= j && j <= n) &&
    (0 <= i && i <= m) &&
    (non_negative(n)) &&
    (res == i * n + j) &&
    ((j < n) => res >= i * n)
    */
for(int j = 0; j < n; j++) {
                res = res + 1;
            }
        }
        return sign * res;
}