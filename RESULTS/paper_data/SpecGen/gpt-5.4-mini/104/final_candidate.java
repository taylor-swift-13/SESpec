class DominantIndex {

    //@ requires nums != null && nums.length > 0;
 
    //@             (\forall int j; 0 <= j && j < nums.length && j != i; 2 * nums[j] <= nums[i]) == false);
    //@ ensures \result != -1 ==> 0 <= \result && \result < nums.length;
    //@ ensures \result != -1 ==> (\forall int j; 0 <= j && j < nums.length && j != \result; 2 * nums[j] <= nums[\result]);
    public static int dominantIndex(int[] nums) {
        int biggest_index = 0;

        //@ maintaining 0 <= biggest_index && biggest_index < nums.length;
        //@ maintaining (\forall int j; 0 <= j && j <= i && j < nums.length; nums[j] <= nums[biggest_index]);
        //@ decreases nums.length - i;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] > nums[biggest_index])
                biggest_index = i;
        }

        //@ maintaining 0 <= biggest_index && biggest_index < nums.length;
        //@ maintaining (\forall int j; 0 <= j && j < i; j != biggest_index ==> 2 * nums[j] <= nums[biggest_index]);
        //@ decreases nums.length - i;
        for (int i = 0; i < nums.length; i++) {
            if (i != biggest_index && 2 * nums[i] > nums[biggest_index])
                return -1;
        }

        return biggest_index;
    }
}
