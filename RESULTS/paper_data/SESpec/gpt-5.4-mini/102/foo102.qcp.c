#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo102(int num) 
/*@

Require emp
Ensure Results(__return)
*/{

       
  /*@ Inv
    (num >= 0 || num@pre < 0) &&
    ((num@pre < 10) => (num == num@pre)) &&
    ((num@pre >= 10) => (num >= 0))
    */
while (num >= 10) {
            int sum = 0;
            
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant num >= 0;
          loop invariant sum >= 0;
          loop assigns num, sum;
            */
            /*@ Inv
    (num >= 0) &&
    (sum >= 0)
    */
while (num > 0) {
                sum += num % 10;
                num /= 10;
            }
            
            num = sum;
        }
        return num;
}