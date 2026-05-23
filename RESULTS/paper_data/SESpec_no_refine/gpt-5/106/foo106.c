
#include <limits.h>

/*@
  assigns \nothing;
  ensures nums_len == 0 ==> \result == INT_MAX;
  ensures nums_len > 0 ==> (
    \exists integer k; 0 <= k < nums_len &&
      \result == nums[k] &&
      \forall integer j; 0 <= j < nums_len ==>
        ( ((nums[k] < 0 ? -nums[k] : nums[k]) < (nums[j] < 0 ? -nums[j] : nums[j])) ||
          ( ((nums[k] < 0 ? -nums[k] : nums[k]) == (nums[j] < 0 ? -nums[j] : nums[j])) && nums[k] >= nums[j] ) )
  );
*/
int foo106(int * nums, int nums_len) {

        int ans = INT_MAX;

        /*@ 
          loop invariant 0 <= i <= nums_len;
                ans == nums[k] &&
                \forall integer j; 0 <= j < i ==> 
                  ( ( (nums[k] < 0 ? -nums[k] : nums[k]) < (nums[j] < 0 ? -nums[j] : nums[j]) ) ||
                    ( (nums[k] < 0 ? -nums[k] : nums[k]) == (nums[j] < 0 ? -nums[j] : nums[j]) && nums[k] >= nums[j] ) ));
          loop assigns i, ans;
          loop variant nums_len - i;
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
