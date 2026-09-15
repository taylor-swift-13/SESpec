
#include <limits.h>

/*@
logic integer iabs(integer x) = (x < 0 ? -x : x);
*/

/*@
  requires 0 <= nums_len;
  requires nums_len == 0 || \valid_read(nums + (0 .. nums_len-1));
  assigns \nothing;
  ensures nums_len == 0 ==> \result == INT_MAX;
  ensures nums_len > 0 ==> \exists integer k; 0 <= k < nums_len && \result == nums[k];
  ensures nums_len > 0 ==> \forall integer j; 0 <= j < nums_len ==>
            (iabs((integer)\result) < iabs((integer)nums[j]) ||
             (iabs((integer)\result) == iabs((integer)nums[j]) && \result >= nums[j]));
  ensures \result == INT_MAX || (\exists integer k; 0 <= k < nums_len && \result == nums[k]);
*/
int foo106(int * nums, int nums_len) {
    if (nums_len == 0) {
        return INT_MAX;
    }

    int ans = nums[0];

    /*@
      loop invariant 1 <= i <= nums_len;
      loop invariant \exists integer k; 0 <= k < i && ans == nums[k];
      loop invariant \forall integer j; 0 <= j < i ==>
            (iabs((integer)ans) < iabs((integer)nums[j]) ||
             (iabs((integer)ans) == iabs((integer)nums[j]) && ans >= nums[j]));
      loop assigns i, ans;
      loop variant nums_len - i;
    */
    for (int i = 1; i < nums_len; i++) {
        int num = nums[i];
        int absNum = (num < 0 ? -num : num);
        int absAns = (ans < 0 ? -ans : ans);
        if (absNum < absAns || (absNum == absAns && num > ans)) {
            ans = num;
        }
    }

    return ans;
}
