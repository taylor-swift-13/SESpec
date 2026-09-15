class IsMonotonic {
    /*@ spec_public @*/ 
    public boolean isMonotonic(int[] nums) {
        boolean inc = true, dec = true;
        int n = nums.length;

        //@ maintaining 0 <= i && i <= n + 1;  
 
        //@ decreases n - i;
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] > nums[i + 1]) {
                inc = false;
            }
            if (nums[i] < nums[i + 1]) {
                dec = false;
            }
        }

        //@ ensures \result == (inc || dec);
        return inc || dec;
    }
}
