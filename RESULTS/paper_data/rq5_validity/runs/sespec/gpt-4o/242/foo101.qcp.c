#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo101(int * nums, int nums_len);

int foo101(int * nums, int nums_len) 
/*@
With nums_l
Require store_int_array(nums, nums_len, nums_l) && nums_len > 0 && nums_len < 100
Ensure Results(__return)
*/{

        int max = nums[0];
        int min = nums[0];
       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  nums_l,    
    store_int_array(nums, nums_len, nums_l) && nums_len > 0 && nums_len < 100 &&
    (1 <= i && i <= nums_len) &&
(max == max_in_range(nums, 0, i)) &&
(min == min_in_range(nums, 0, i)) &&
(nums_len == nums_len@pre) &&
(nums == nums@pre
      loop assigns i, max, min)
    */
    
    for (int i = 1; i < nums_len; i++) {
        if (nums[i] > max) {
            max = nums[i];
        }
        if (nums[i] < min) {
            min = nums[i];
        }
    }
        return max - min;
}