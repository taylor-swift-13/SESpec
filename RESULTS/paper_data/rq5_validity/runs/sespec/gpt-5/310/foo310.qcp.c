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
    (0 <= left) &&
    (left <= right + 1) &&
    (left <= num + 1) &&
    (right >= -1) &&
    ((-1 <= right) && (right <= num)) &&
    (num == num@pre) &&
    ((0 <= num@pre)) &&
    (left == 0 || (exists (k:Z), 0 <= k && k < left && k * k < num)) &&
    ((left <= right) => (right - left <= num@pre)) &&
    ((0 <= num@pre) => (0 <= left && right <= num@pre)) &&
    ((0 <= num@pre) => ((right == num@pre && left == 0 && num == num@pre) || (0 <= left && left <= right + 1 && -1 <= right && right <= num@pre))) &&
    ((!(0 <= num@pre)) => ((right == num@pre) && (left == 0) && (num == num@pre))) &&
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