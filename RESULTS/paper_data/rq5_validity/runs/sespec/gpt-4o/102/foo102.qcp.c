#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo102(int num);

int foo102(int num) 
/*@

Require emp
Ensure Results(__return)
*/{

       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (num >= 0) &&
((num@pre < 10) => (num == num@pre)
      loop assigns num)
    */
    
    while (num >= 10) {
        int sum = 0;

        /*@
          loop invariant num >= 0;
          loop invariant sum >= 0;
          loop assigns sum, num;
        */
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }

        num = sum;
    }
        return num;
}