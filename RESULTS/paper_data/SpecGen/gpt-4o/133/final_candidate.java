class MoveZeroes {
    //@ ensures (\exists int i; 0 < i && i < nums.length; nums[i] != 0 ==> (\forall int j; i < j && j < nums.length; nums[j] == 0));  
    public void moveZeroes(int[] nums) {
        int n = nums.length, left = 0, right = 0;
        //@ maintaining 0 <= left && left <= right && right <= n;
        //@ maintaining (\forall int i; 0 <= i && i < left; nums[i] != 0);
        //@ maintaining (\forall int i; left <= i && i < right; nums[i] == 0);
        //@ decreases n - right;
        while (right < n) {
            if (nums[right] != 0) {
                swap(nums, left, right);
                left++;
            }
            right++;
        }
    }

    //@ requires 0 <= left && left < nums.length;
    //@ requires 0 <= right && right < nums.length;
    //@ ensures nums[left] == \old(nums[right]) && nums[right] == \old(nums[left]);
    public void swap(int[] nums, int left, int right) {
        int temp = nums[left];
        nums[left] = nums[right];
        nums[right] = temp;
    }
}
