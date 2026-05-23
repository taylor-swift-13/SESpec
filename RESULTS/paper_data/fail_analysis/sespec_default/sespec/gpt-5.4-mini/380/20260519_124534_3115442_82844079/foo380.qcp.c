#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo380(int number);

int foo380(int number) 
/*@

Require emp
Ensure Results(__return)
*/{

        int sum = 0;
       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (number == number@pre
          loop assigns i, sum)
    */
    
            for (int i = 1; i <= number / 2; i++) {
            if (number % i == 0) {
                sum += i;
            }
        }
        return sum;
}