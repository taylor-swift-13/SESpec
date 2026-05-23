#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo102(int num);

int foo102(int num) 
/*@

Require emp
Ensure (__return < 10 && __return >= 0)
*/
{

       
  /*0*/ 
 /*@ Inv
    (num >= 0)
    */
while (num >= 10) {
            int sum = 0;
           
  /*1*/ 
 /*@ Inv
    (sum >= 0) &&
    (num >= 0)
    */
while (num > 0) {
                sum += num % 10;
                num /= 10;
            }
            num = sum;
        }
        return num;
}