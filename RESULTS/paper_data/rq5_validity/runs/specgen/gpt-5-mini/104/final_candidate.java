class DominantIndex {

    //@ requires nums != null && nums.length > 0;
    //@ ensures (\result >= 0 && \result < nums.length) ==>
    //@            (\forall int j; 0 <= j && j < nums.length; nums[\result] >= nums[j])
    //@            && (\forall int j; 0 <= j && j < nums.length && j != \result; 2*nums[j] <= nums[\result]);
    //@ ensures \result == -1 ==>
    //@            (\forall int m; 0 <= m && m < nums.length ==>
    //@                (\exists int j; 0 <= j && j < nums.length && j != m && 2*nums[j] > nums[m]));
    //@ ensures (\result == -1) || (0 <= \result && \result < nums.length);
    public static int dominantIndex(int[] nums) {
        int biggest_index = 0;

        //@ maintaining 0 <= i && i <= nums.length;
        //@ maintaining 0 <= biggest_index && biggest_index < nums.length;
        //@ maintaining (\forall int k; 0 <= k && k < i; nums[biggest_index] >= nums[k]);
        //@ decreases nums.length - i;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] > nums[biggest_index])
                biggest_index = i;
        }

        //@ maintaining 0 <= i && i <= nums.length;
        //@ maintaining 0 <= biggest_index && biggest_index < nums.length;
        //@ maintaining (\forall int k; 0 <= k && k < nums.length; nums[biggest_index] >= nums[k]);
        //@ maintaining (\forall int k; 0 <= k && k < i && k != biggest_index; 2*nums[k] <= nums[biggest_index]);
        //@ decreases nums.length - i;
        for (int i = 0; i < nums.length; i++) {
            if (i != biggest_index && 2 * nums[i] > nums[biggest_index])
                return -1;
        }

        return biggest_index;
    }
}