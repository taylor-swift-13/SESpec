#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
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

           
  /*@ Inv
    (result >= (num1 > num2 ? num1 : num2)) &&
    (result <= INT_MAX) &&
    (num1 > 0 && num2 > 0) &&
    (result - (num1 > num2 ? num1 : num2) >= 0) &&
    ((forall (k:Z), (num1 > num2 ? num1 : num2) <= k < result => !(k % num1 == 0 && k % num2 == 0))) &&
    ((forall (k:Z), (num1 > num2 ? num1 : num2) <= k < result => k < INT_MAX)) &&
    ((result == (num1 > num2 ? num1 : num2)) || (result > (num1 > num2 ? num1 : num2))) &&
    ((!(result < INT_MAX)) => (result == INT_MAX))
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