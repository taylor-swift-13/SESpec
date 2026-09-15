#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo357(int n);

int foo357(int n) 
/*@

Require emp
Ensure (exists count_64 temp_63, temp_63 <= 0 && count_64 >= 0 && temp_63 == n >> count_64 && __return == (n | 0))
*/
{

        int count = 0;
        int res = 0;
        int temp = n;
       
  /*0*/ 
 /*@ Inv
    (count >= 0) &&
    (temp == (n >> count))
    */
while (temp > 0) {
            if (count % 2 == 1) {
                res |= (1 << count);
            }
            count++;
            temp >>= 1;
        }
        return (n | res);
}