#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo289(int number);

int foo289(int number) 
/*@

Require emp
Ensure Results(__return)
*/{

        int sum = 0;
       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (1 <= i) &&
(sum == partial_div_sum(number, i)) &&
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