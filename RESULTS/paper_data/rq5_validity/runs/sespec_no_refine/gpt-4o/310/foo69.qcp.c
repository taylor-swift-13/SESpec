#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo69(int num);

int foo69(int num) 
/*@

Require emp
Ensure Results(__return)
*/{

        if (num < 0) {
            return -1;
        }
        int left = 0;
        int right = num;
       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (0 <= left && left <= right + 1 && right <= num) &&
(num == num@pre
      loop assigns left, right)
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