#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo356(int n);

int foo356(int n) 
/*@

Require emp
Ensure (exists count_66 temp_65 res_64, temp_65 <= 0 && 0 <= count_66 && temp_65 <= n && (n > 0 => 0 <= count_66) && (!(n > 0) => temp_65 == n && count_66 == 0 && res_64 == 0 && n == n) && __return == (n ^ res_64))
*/
{

        int res = 0;
        int count = 0;
        int temp = n;
       
  /*@ Inv
    (0 <= count) &&
    (temp <= n@pre) &&
    (n == n@pre) &&
    ((n@pre > 0) => (0 <= count)) &&
    ((!(n@pre > 0)) => ((temp == n@pre) && (count == 0) && (res == 0) && (n == n@pre)))
    */
while (temp > 0) {
        if (count % 2 == 0) {
            res = res | (1 << count);
        }
        count++;
        temp >>= 1;
    }
        return n ^ res;
}