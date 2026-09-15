
#include <limits.h>

/*@ 
  logic integer abs_int(integer x) = x < 0 ? -x : x;
*/

int foo106(int * nums, int nums_len) {

        int ans = INT_MAX;

        /*@
          loop invariant ans == INT_MAX || \exists integer k; 0 <= k < i && ans == nums[k];
          loop invariant \forall integer k; 0 <= k < i ==> abs_int(ans) <= abs_int(nums[k]);
          loop invariant \forall integer k; 0 <= k < i ==> (abs_int(nums[k]) == abs_int(ans) ==> nums[k] <= ans);
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
