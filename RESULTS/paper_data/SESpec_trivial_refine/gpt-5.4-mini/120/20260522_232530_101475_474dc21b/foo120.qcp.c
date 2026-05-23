#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo120(int * nums, int nums_len) 
/*@
With nums_l
Require store_int_array(nums, nums_len, nums_l)
Ensure Results(__return)
*/{

        int inc = 1, dec = 1;
        int n = nums_len;
       
  /*0*/ 
 /*@ Inv
    exists  nums_l,    
    store_int_array(nums, nums_len, nums_l) &&
    (0 <= i) &&
    (inc == 0 || inc == 1) &&
    (dec == 0 || dec == 1) &&
    (inc == 1 => (forall (k:Z), 0 <= k && k < i => nums_l[k] <= nums_l[k + 1])) &&
    (dec == 1 => (forall (k:Z), 0 <= k && k < i => nums_l[k] >= nums_l[k + 1]))
    */
for (int i = 0; i < n - 1; ++i) {
            if (nums[i] > nums[i + 1]) {
                inc = 0;
            }
            if (nums[i] < nums[i + 1]) {
                dec = 0;
            }
        }
        return inc || dec;
}