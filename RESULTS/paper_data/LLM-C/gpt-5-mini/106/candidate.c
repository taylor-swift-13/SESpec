int findClosestNumber(int * nums, int nums_len);

/*@
    requires nums_len > 0;
    requires \valid(nums + (0 .. nums_len-1));
    assigns \nothing;
    ensures \exists integer i; 0 <= i < nums_len && \result == nums[i] &&
            \forall integer j; 0 <= j < nums_len ==>
                ( \abs(nums[j]) > \abs(\result) ||
                  ( \abs(nums[j]) == \abs(\result) ==> nums[j] <= \result ) );
*/
int findClosestNumber(int * nums, int nums_len) {

        int ans = Integer.MAX_VALUE;

        /*@
            loop invariant 0 <= i <= nums_len;
            loop invariant i == 0 || (\exists integer m; 0 <= m < i && ans == nums[m]);
            loop invariant \forall integer j; 0 <= j < i ==>
                ( \abs(nums[j]) > \abs(ans) ||
                  ( \abs(nums[j]) == \abs(ans) ==> nums[j] <= ans ) );
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
