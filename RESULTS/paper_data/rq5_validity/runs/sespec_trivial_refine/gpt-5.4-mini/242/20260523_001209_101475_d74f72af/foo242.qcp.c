#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo242(int * nums, int nums_len) 
/*@
With nums_l
Require store_int_array(nums, nums_len, nums_l)
Ensure Results(__return)
*/{

        int max = nums[0];
        int min = nums[0];
       
  /*@ Inv
    exists  nums_l,    
    store_int_array(nums, nums_len, nums_l) &&
    (1 <= i && i <= nums_len) &&
    (max >= min) &&
    (forall (j:Z), 1 <= j && j < i => max >= nums_l[j]) &&
    (forall (j:Z), 1 <= j && j < i => min <= nums_l[j])
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