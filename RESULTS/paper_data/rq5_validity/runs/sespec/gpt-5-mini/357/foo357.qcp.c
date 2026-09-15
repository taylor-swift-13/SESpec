#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo357(int n);

int foo357(int n) 
/*@

Require emp
Ensure (exists count_66 temp_65 res_64, temp_65 <= 0 && 0 <= count_66 && temp_65 == n >> count_66 && (!(n > 0) => temp_65 == n && res_64 == 0 && count_66 == 0 && n == n) && __return == (n | res_64))
*/
{

        int count = 0;
        int res = 0;
        int temp = n;
       
  /*0*/ 
 /*@ Inv
    (0 <= count) &&
    (temp == (n@pre >> count)) &&
    ((!(n@pre > 0)) => ((temp == n@pre) && (res == 0) && (count == 0) && (n == n@pre))) &&
    (n == n@pre)
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