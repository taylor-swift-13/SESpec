
#include <limits.h>

/*@
  logic integer abs_int(integer x) = x >= 0 ? x : -x;
*/

/*@
  requires nums_len >= 0;
  requires \valid(&nums[0] + (0..nums_len-1));
  requires \forall integer i; 0 <= i < nums_len ==> 0 <= nums[i] <= 100;
  assigns \nothing;
  ensures \forall integer k; 0 <= k < nums_len ==> nums[k] == \old(nums[k]);
  ensures nums_len == 0 ==> \true;
  ensures nums_len > 0 ==> (\forall integer k; 0 <= k < nums_len ==> \result <= nums[k]);
  ensures nums_len > 0 ==> \true;
  ensures nums_len > 0 ==> \true;
  ensures \true;
  ensures \result == \result;
*/
int foo106(int * nums, int nums_len) {

        int ans = INT_MAX;

        /* >>> LOOP INVARIANT TO FILL <<< */
        /*@
          loop invariant i == 0 ==> ans == INT_MAX;
          loop invariant \forall integer k; 0 <= k < i ==> abs_int(ans) <= abs_int(nums[k]);
          loop invariant \forall integer k; 0 <= k < i ==> (abs_int(ans) == abs_int(nums[k]) ==> ans >= nums[k]);
          loop invariant \forall integer k; 0 <= k < nums_len ==> nums[k] == \at(nums[k], Pre);
          loop invariant 0 <= i && (i < nums_len ==> i + 1 <= nums_len);
          loop invariant (i < nums_len) ==> (0 <= i < nums_len);
          loop assigns i, ans;
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
