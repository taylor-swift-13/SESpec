#include <limits.h>

/*@ 
    requires nums_len >= 0;
    requires \valid_read(nums + (0 .. nums_len - 1));
    assigns \nothing;
    ensures \exists integer i; 0 <= i < nums_len && \result == nums[i];
    ensures \forall integer i; 0 <= i < nums_len ==> 
                ((nums[i] < 0 ? -nums[i] : nums[i]) >= (\result < 0 ? -\result : \result));
*/
int findClosestNumber(int * nums, int nums_len) {

        int ans = INT_MAX;
        /*@
            loop invariant 0 <= i <= nums_len;
            loop invariant \forall integer j; 0 <= j < i ==>
                ((nums[j] < 0 ? -nums[j] : nums[j]) >= (ans < 0 ? -ans : ans));
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
