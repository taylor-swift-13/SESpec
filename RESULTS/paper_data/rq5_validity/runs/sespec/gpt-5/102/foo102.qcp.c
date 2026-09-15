#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (digit_sum_once : Z -> Z) */
int foo102(int num) 
/*@

Require emp
Ensure Results(__return)
*/{

       
  /*@ Inv
    ((num@pre < 10) => (num == num@pre)) &&
    ((num@pre >= 10) => (num >= 0))
    */
while (num >= 10) {
            int sum = 0;
            
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant sum >= 0;
          loop invariant num >= 0;
          loop invariant \forall integer t; t == 0 ==> (sum == sum);
          loop assigns num, sum;
            */
            /*@ Inv
    (sum >= 0) &&
    (num >= 0) &&
    ((num > 0) => (num / 10 < num)) &&
    (forall (t:Z), t == 0 => (sum == sum))
    */
while (num > 0) {
                sum += num % 10;
                num /= 10;
            }
            
            num = sum;
        }
        return num;
}