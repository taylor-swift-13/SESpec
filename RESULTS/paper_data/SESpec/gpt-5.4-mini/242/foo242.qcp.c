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
    (0 <= i) &&
    (max >= min) &&
    (forall (k:Z), 0 <= k && k < i => nums_l[k] <= max) &&
    (forall (k:Z), 0 <= k && k < i => nums_l[k] >= min) &&
    (forall (k:Z), 0 <= k && k < i => min <= nums_l[k]) &&
    (forall (k:Z), 0 <= k && k < i => nums_l[k] <= max) &&
    (forall (k:Z), 0 <= k && k < nums_len => nums_l[k] == nums_l[k]@pre) &&
    ((i >= nums_len) => (max >= min))
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