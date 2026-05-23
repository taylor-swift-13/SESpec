#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo43(int * nums, int nums_len);

int foo43(int * nums, int nums_len) 
/*@
With nums_l
Require store_int_array(nums, nums_len, nums_l) && nums_len > 0 && nums_len < 100
Ensure Results(__return)
*/{

        int inc = 1, dec = 1;
        int n = nums_len;
       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  nums_l,    
    store_int_array(nums, nums_len, nums_l) && nums_len > 0 && nums_len < 100 &&
    (0 <= i && i <= n - 1) &&
(n == nums_len@pre) &&
(nums_len == nums_len@pre) &&
(nums == nums@pre) &&
(forall (k:Z), 0 <= k && k < i => nums_l[k] == nums_l[k]@pre
      loop assigns i, inc, dec)
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