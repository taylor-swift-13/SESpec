#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (slice_max : Z -> Z -> Z -> Z) */
/*@ Extern Coq (slice_min : Z -> Z -> Z -> Z) */
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
    (max == slice_max(nums, 0, i)) &&
    (min == slice_min(nums, 0, i)) &&
    (forall (k:Z), 0 <= k && k < nums_len => nums_l[k] == nums_l[k]@pre)
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