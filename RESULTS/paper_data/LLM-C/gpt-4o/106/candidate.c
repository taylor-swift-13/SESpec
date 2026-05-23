/*@
    requires \valid(nums + (0 .. nums_len - 1));
    requires nums_len > 0;
    ensures \exists integer i; 0 <= i < nums_len && \result == nums[i];
    ensures \forall integer i; 0 <= i < nums_len ==> 
                (\abs(nums[i]) > \abs(\result) || 
                (\abs(nums[i]) == \abs(\result) && nums[i] <= \result));
    assigns \nothing;
*/
int findClosestNumber(int * nums, int nums_len) {

        int ans = 2147483647; // Integer.MAX_VALUE equivalent in C

        /*@
        loop invariant 0 <= i <= nums_len;
        loop invariant \exists integer j; 0 <= j < i && ans == nums[j];
        loop invariant \forall integer j; 0 <= j < i ==> 
                        (\abs(nums[j]) > \abs(ans) || 
                        (\abs(nums[j]) == \abs(ans) && nums[j] <= ans));
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
