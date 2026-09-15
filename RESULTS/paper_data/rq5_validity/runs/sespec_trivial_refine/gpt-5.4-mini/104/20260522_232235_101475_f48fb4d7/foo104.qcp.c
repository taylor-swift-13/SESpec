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
    (0 <= i) &&
    (0 <= biggest_index && biggest_index <= i) &&
    (forall (j:Z), 0 <= j && j < i => nums_l[biggest_index] >= nums_l[j])
    */
for (int i = 0; i < nums_len; i++) {
            if (nums[i] > nums[biggest_index])
                biggest_index = i;
        }

       
  /*1*/ 
 /*@ Inv
    exists  nums_l,    
    store_int_array(nums, nums_len, nums_l) &&
    (0 <= i && i <= nums_len) &&
    (0 <= biggest_index && biggest_index < nums_len) &&
    (forall (j:Z), 0 <= j && j < i => (j == biggest_index || 2 * nums_l[j] <= nums_l[biggest_index]))
    */
for (int i = 0; i < nums_len; i++) {
            if (i != biggest_index && 2 * nums[i] > nums[biggest_index])
                return -1;
        }

        return biggest_index;
}