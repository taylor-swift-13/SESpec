
/*@
logic integer iabs(integer x) = (x < 0 ? -x : x);
*/

int foo106(int * nums, int nums_len) {

        int ans = INT_MAX;

        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= i <= nums_len;
          loop invariant \forall integer j; 0 <= j < i ==> (iabs((integer)ans) < iabs((integer)nums[j]) || (iabs((integer)ans) == iabs((integer)nums[j]) && ans >= nums[j]));
          loop assigns i, ans, num, absNum, absAns;
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
