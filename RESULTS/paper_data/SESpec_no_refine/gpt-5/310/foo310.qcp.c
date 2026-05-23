#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo310(int num);

int foo310(int num) 
/*@

Require emp
Ensure ((0 + (num - 0) / 2) * (0 + (num - 0) / 2) == num && 0 <= num && num >= 0 && __return == 0 + (num - 0) / 2) || (num < 0 && __return == -1)
*/
{

        if (num < 0) {
            return -1;
        }
        int left = 0;
        int right = num;
       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
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