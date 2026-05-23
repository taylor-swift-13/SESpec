
#include <limits.h>

/*@ 
  logic integer abs_int(integer x) = x < 0 ? -x : x;
*/

/*@
  requires \valid(&nums[0] + (0..nums_len-1));
  requires \forall integer i; 0 <= i < nums_len ==> 0 <= nums[i] <= 100;
  requires nums_len > 0;
  requires nums_len < 100;
  assigns \nothing;
  ensures \forall integer k; 0 <= k < nums_len ==>
            (abs_int(\result) < abs_int(nums[k]) ||
             (abs_int(\result) == abs_int(nums[k]) && \result >= nums[k]));
  ensures \exists integer k; 0 <= k < nums_len && \result == nums[k];
  
*/
int foo106(int * nums, int nums_len) {

        int ans = INT_MAX;

        
            
        /*@
          loop invariant 0 <= i <= nums_len;
          loop invariant \forall integer k; 0 <= k < i ==>
            (abs_int(ans) < abs_int(nums[k]) ||
             (abs_int(ans) == abs_int(nums[k]) && ans >= nums[k]));
          loop invariant \forall integer k; 0 <= k < nums_len ==> nums[k] == \at(nums[k], Pre);
          loop assigns ans;
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
