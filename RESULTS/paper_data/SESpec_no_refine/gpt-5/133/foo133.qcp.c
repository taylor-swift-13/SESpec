#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

void foo56_helper1_c133(int * nums, int nums_len);
void foo133(int * nums, int nums_len, int left, int right);

void foo133(int * nums, int nums_len, int left, int right) 
/*@
With nums_l
Require store_int_array(nums, nums_len, nums_l) && nums_len > 0 && nums_len < 100
Ensure emp
*/{

        int temp = nums[left];
        nums[left] = nums[right];
        nums[right] = temp;
}