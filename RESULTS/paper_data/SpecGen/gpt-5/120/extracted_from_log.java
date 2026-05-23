class IsMonotonic {
    /*@ 
      @ requires nums != null;
      @ assignable \nothing;
      @ ensures nums == \old(nums);
      @ ensures nums.length <= 1 ==> \result;
      @*/
    public boolean isMonotonic(int[] nums) {
        boolean inc = true, dec = true;
        int n = nums.length;
        /*@ 
          @ maintaining n == nums.length;
          @ maintaining 0 <= i && i <= n - 1;
          @ decreases (n - 1 - i);
          @*/
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] > nums[i + 1]) {
                inc = false;
            }
            if (nums[i] < nums[i + 1]) {
                dec = false;
            }
        }
        return inc || dec;
    }
}