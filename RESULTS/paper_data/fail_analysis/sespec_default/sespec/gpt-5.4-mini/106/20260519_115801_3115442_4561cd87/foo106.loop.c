
#include <limits.h>

/*@ 
  logic integer abs_int(integer x) = x < 0 ? -x : x;
*/

int foo106(int * nums, int nums_len) {

        int ans = INT_MAX;

        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= i <= nums_len;
          loop invariant \forall integer k; 0 <= k < i ==>
            (abs_int(ans) < abs_int(nums[k]) ||
             (abs_int(ans) == abs_int(nums[k]) && ans >= nums[k]));
          loop invariant \forall integer k; 0 <= k < nums_len ==> nums[k] == \at(nums[k], Pre);
          loop assigns i, num, absNum, absAns, ans;
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
