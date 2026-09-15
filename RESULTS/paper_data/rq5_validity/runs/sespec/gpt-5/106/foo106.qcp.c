#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (abs_int : Z -> Z) */
int foo106(int * nums, int nums_len) 
/*@
With nums_l
Require store_int_array(nums, nums_len, nums_l)
Ensure Results(__return)
*/{

        int ans = INT_MAX;

       
  /*@ Inv
    exists  nums_l,    
    store_int_array(nums, nums_len, nums_l) &&
    (i == 0 => ans == INT_MAX) &&
    (forall (k:Z), 0 <= k && k < i => abs_int(ans) <= abs_int(nums_l[k])) &&
    (forall (k:Z), 0 <= k && k < i => (abs_int(ans) == abs_int(nums_l[k]) => ans >= nums_l[k])) &&
    (forall (k:Z), 0 <= k && k < nums_len => nums_l[k] == nums_l[k]@pre) &&
    (0 <= i && (i < nums_len => i + 1 <= nums_len)) &&
    ((i < nums_len) => (0 <= i && i < nums_len))
    */
for(int i = 0; i < nums_len; i++) {
            int num = nums[i];
            int absNum = (num<0?-num:num);
            int absAns = (ans<0?-ans:ans);
            if(absNum < absAns || (absNum == absAns && num > ans)) {
                ans = num;
            }
        }

        return ans;
}