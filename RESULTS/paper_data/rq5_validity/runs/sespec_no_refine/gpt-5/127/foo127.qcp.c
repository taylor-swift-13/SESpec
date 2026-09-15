#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

#include <limits.h>
int foo127(int num1, int num2);

int foo127(int num1, int num2) 
/*@

Require emp
Ensure Results(__return)
*/{

        if (num1 == 0 || num2 == 0) {
            return -1;
        }
        if (num1 < 0)
            num1 = -num1;
        if (num2 < 0)
            num2 = -num2;

            int result = (num1 > num2) ? num1 : num2;

           
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (is_pos(num1) && is_pos(num2)) &&
(result >= num1 && result >= num2) &&
(result > 0) &&
(forall (k:Z), (num1 <= k && k < result) => (k % num1 != 0 || k % num2 != 0)
          loop assigns result)
    */
    
            while (result < INT_MAX)
            {
                if (result % num1 == 0 && result % num2 == 0)
                {
                    break;
                }
                result++;
            }

        if (result % num1 == 0 && result % num2 == 0) {
            return result;
        }
        return -1;
}