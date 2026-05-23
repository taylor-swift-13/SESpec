#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo310(int num);

int foo310(int num) 
/*@

Require emp
Ensure (exists left_59, left_59 > __return && 0 <= left_59 && left_59 <= num && 0 <= __return && __return <= num && left_59 <= __return + 1 && num >= 0) || (exists left_59 right_58, (left_59 + (right_58 - left_59) / 2) * (left_59 + (right_58 - left_59) / 2) == num && left_59 <= right_58 && 0 <= left_59 && left_59 <= num && 0 <= right_58 && right_58 <= num && left_59 <= right_58 + 1 && num >= 0 && __return == left_59 + (right_58 - left_59) / 2) || (num < 0 && __return == -1)
*/
{

        if (num < 0) {
            return -1;
        }
        int left = 0;
        int right = num;
       
  /*@ Inv
    (0 <= left && left <= num) &&
    (0 <= right && right <= num) &&
    (left <= right + 1) &&
    (num == num@pre)
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