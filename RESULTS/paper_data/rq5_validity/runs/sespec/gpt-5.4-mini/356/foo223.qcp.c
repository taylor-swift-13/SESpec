#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo223(int n);

int foo223(int n) 
/*@

Require emp
Ensure Results(__return)
*/{

        int res = 0;
        int count = 0;
        int temp = n;
       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((n@pre > 0) => (count >= 0)) &&
((n@pre > 0) => (temp <= n@pre)) &&
((n@pre > 0) => (temp <= n@pre)) &&
((!(n@pre > 0)) => ((temp == n@pre)&&(count == 0)&&(res == 0)&&(n == n@pre))) &&
(n == n@pre
          loop assigns res, temp, count)
    */
    
            while (temp > 0) {
            if (count % 2 == 0) {
                res = res | (1 << count);
            }
            count++;
            temp >>= 1;
        }
        return n ^ res;
}