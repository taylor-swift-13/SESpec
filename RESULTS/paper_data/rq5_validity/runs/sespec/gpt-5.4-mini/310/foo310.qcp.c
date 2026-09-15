#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo310(int num) 
/*@

Require emp
Ensure Results(__return)
*/{

        if (num < 0) {
            return -1;
        }
        int left = 0;
        int right = num;
       
  /*@ Inv
    (0 <= left && left <= num + 1) &&
    (-1 <= right && right <= num) &&
    (left <= right + 1) &&
    ((0 <= num@pre) => (((right == num@pre)&&(left == 0)&&(num == num@pre)) || (0 <= left && left <= num + 1))) &&
    ((0 <= num@pre) => (((right == num@pre)&&(left == 0)&&(num == num@pre)) || (-1 <= right && right <= num))) &&
    ((!(0 <= num@pre)) => ((right == num@pre)&&(left == 0)&&(num == num@pre))) &&
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