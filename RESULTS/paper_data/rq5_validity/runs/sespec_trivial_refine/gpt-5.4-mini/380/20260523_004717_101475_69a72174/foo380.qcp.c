#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
/*@ Extern Coq (divisible : Z -> Z -> Prop) */

int foo380(int number) 
/*@

Require emp
Ensure Results(__return)
*/{

        int sum = 0;
       
  /*0*/ 
 /*@ Inv
    (1 <= i) &&
    (i <= number / 2 + 1) &&
    (sum == \sum(integer k = 1, i - 1, (divisible(number, k) ? k : 0)))
    */
for (int i = 1; i <= number / 2; i++) {
            if (number % i == 0) {
                sum += i;
            }
        }
        return sum;
}