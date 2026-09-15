#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo224(int n);

int foo224(int n) 
/*@

Require emp
Ensure Results(__return)
*/{

        int count = 0;
        int res = 0;
        int temp = n;
       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((!(n@pre > 0)) => ((temp == n@pre)&&(res == 0)&&(count == 0)&&(n == n@pre))) &&
(n == n@pre
          loop assigns res, temp, count)
    */
    
            while (temp > 0) {
            if (count % 2 == 1) {
                res |= (1 << count);
            }
            count++;
            temp >>= 1;
        }
        return (n | res);
}