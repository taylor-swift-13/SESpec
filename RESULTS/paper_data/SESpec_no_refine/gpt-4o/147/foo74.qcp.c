#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo74(int n);

int foo74(int n) 
/*@

Require emp
Ensure Results(__return)
*/{

        int temp = n;
       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((!(n@pre != 0 && n@pre % 3 == 0)) => 
                      ((temp == n@pre) && (n == n@pre))) &&
(n == n@pre
      loop assigns temp)
    */
    
    while (temp != 0 && temp % 3 == 0) {
        temp /= 3;
    }
        return temp == 1;
}