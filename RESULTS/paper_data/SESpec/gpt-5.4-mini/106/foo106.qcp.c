#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

#include <limits.h>
int foo106(int * nums, int nums_len);

int foo106(int * nums, int nums_len) 
/*@
With nums_l
Require store_int_array(nums, nums_len, nums_l) && nums_len > 0 && nums_len < 100
Ensure Results(__return)
*/{

        int ans = INT_MAX;

       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  nums_l,    
    store_int_array(nums, nums_len, nums_l) && nums_len > 0 && nums_len < 100 &&
    (ans == INT_MAX || exists (k:Z), 0 <= k && k < i && ans == nums_l[k]) &&
(forall (k:Z), 0 <= k && k < i => abs_int(ans) <= abs_int(nums_l[k])) &&
(forall (k:Z), 0 <= k && k < i => (abs_int(nums_l[k]) == abs_int(ans) => nums_l[k] <= ans)) &&
(forall (k:Z), 0 <= k && k < nums_len => nums_l[k] == nums_l[k]@pre
          loop assigns ans)
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