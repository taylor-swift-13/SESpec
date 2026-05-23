#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo104(int * nums, int nums_len) 
/*@
With nums_l
Require store_int_array(nums, nums_len, nums_l)
Ensure Results(__return)
*/{

        int biggest_index = 0;

       
  /*@ Inv
    exists  nums_l,    
    store_int_array(nums, nums_len, nums_l) &&
    (0 <= i && i <= nums_len) &&
    (0 <= biggest_index && biggest_index <= i) &&
    (i == 0 => biggest_index == 0) &&
    (i > 0 => 0 <= biggest_index && biggest_index < i) &&
    (i > 0 => forall (k:Z), 0 <= k && k < i => nums_l[k] <= nums_l[biggest_index]) &&
    (i > 0 => exists (k:Z), 0 <= k && k < i && nums_l[k] == nums_l[biggest_index]) &&
    (nums_len == nums_len@pre) &&
    (nums == nums@pre) &&
    (forall (k:Z), 0 <= k && k < nums_len => nums_l[k] == nums_l[k]@pre)
    */
for (int i = 0; i < nums_len; i++) {
            if (nums[i] > nums[biggest_index])
                biggest_index = i;
        }

       
  /*@ Inv
    exists  nums_l,    
    store_int_array(nums, nums_len, nums_l) &&
    (0 <= i && i <= nums_len) &&
    (0 <= biggest_index && biggest_index <= nums_len) &&
    (forall (k:Z), 0 <= k && k < i => (k == biggest_index || 2 * nums_l[k] <= nums_l[biggest_index])) &&
    (forall (k:Z), 0 <= k && k < nums_len => nums_l[k] == nums_l[k]@pre)
    */
for (int i = 0; i < nums_len; i++) {
            if (i != biggest_index && 2 * nums[i] > nums[biggest_index])
                return -1;
        }

        return biggest_index;
}