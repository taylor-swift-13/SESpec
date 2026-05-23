class IsMonotonic {
    //@ requires nums != null;
    public boolean isMonotonic(int[] nums) {
        boolean inc = true, dec = true;
        for (int i = 0; i + 1 < nums.length; i++) {
            if (nums[i] > nums[i + 1]) inc = false;
            if (nums[i] < nums[i + 1]) dec = false;
        }
        return inc || dec;
    }
}