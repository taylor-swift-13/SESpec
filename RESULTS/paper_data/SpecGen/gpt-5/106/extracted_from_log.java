class Sespec0106 {
    //@ requires nums != null;
    //@ ensures nums.length == 0 ==> \result == Integer.MAX_VALUE;
    //@ ensures nums.length > 0 ==> (\exists int i; 0 <= i && i < nums.length; \result == nums[i]);
    //@ ensures nums.length > 0 ==> (\forall int i; 0 <= i && i < nums.length;
    //@     ((\result < 0 ? -\result : \result) <= (nums[i] < 0 ? -nums[i] : nums[i])));
    //@ ensures nums.length > 0 ==> (\forall int i; 0 <= i && i < nums.length;
    //@     ((nums[i] < 0 ? -nums[i] : nums[i]) == (\result < 0 ? -\result : \result) ==> \result >= nums[i]));
    static int foo106(int[] nums) {
        int ans = Integer.MAX_VALUE;
        //@ maintaining 0 <= i && i <= nums.length;
        //@ maintaining i == 0 ==> ans == Integer.MAX_VALUE;
        //@ maintaining i > 0 ==> (\exists int j; 0 <= j && j < i; ans == nums[j]);
        //@ maintaining i > 0 ==> (\forall int j; 0 <= j && j < i;
        //@     ((ans < 0 ? -ans : ans) <= (nums[j] < 0 ? -nums[j] : nums[j])));
        //@ maintaining i > 0 ==> (\forall int j; 0 <= j && j < i;
        //@     ((nums[j] < 0 ? -nums[j] : nums[j]) == (ans < 0 ? -ans : ans) ==> ans >= nums[j]));
        //@ decreases nums.length - i;
        for (int i = 0; i < nums.length; i++) {
            int num = nums[i];
            int absNum = (num < 0 ? -num : num);
            int absAns = (ans < 0 ? -ans : ans);
            if (absNum < absAns || (absNum == absAns && num > ans)) {
                ans = num;
            }
        }
        return ans;
    }
}