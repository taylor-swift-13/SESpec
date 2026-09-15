#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo356(int n);

int foo356(int n) 
/*@

Require emp
Ensure Results(__return)
*/{

        int res = 0;
        int count = 0;
        int temp = n;
       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (count >= 0) &&
(n == n@pre) &&
(temp == n - count || temp <= n) &&
(count == 0 => res == 0
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