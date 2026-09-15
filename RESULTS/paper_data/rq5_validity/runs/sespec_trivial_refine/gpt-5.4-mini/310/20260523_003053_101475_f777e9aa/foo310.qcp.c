#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo310(int num);

int foo310(int num) 
/*@

Require emp
Ensure (exists left_61, left_61 > __return && 0 <= left_61 && __return <= num && left_61 <= __return + 1 && num@pre >= 0) || (exists left_61 right_60, (left_61 + (right_60 - left_61) / 2) * (left_61 + (right_60 - left_61) / 2) == num && left_61 <= right_60 && 0 <= left_61 && right_60 <= num && left_61 <= right_60 + 1 && num@pre >= 0 && __return == left_61 + (right_60 - left_61) / 2) || (num < 0 && __return == -1)
*/
{

        if (num < 0) {
            return -1;
        }
        int left = 0;
        int right = num;
       
  /*0*/ 
 /*@ Inv
    (0 <= left) &&
    (right <= num) &&
    (left <= right + 1)
    */
while (left <= right) {
            int mid = left + (right - left) / 2;
            if (mid * mid == num) {
                return mid;
            } else if (mid * mid < num) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return right;
}