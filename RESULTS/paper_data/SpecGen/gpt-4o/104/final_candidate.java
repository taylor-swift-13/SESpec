class DominantIndex {

    //@ requires nums != null && nums.length > 0;
 
    //@ ensures (\result != -1) ==> (\forall int i; 0 <= i && i < nums.length; i != \result ==> 2 * nums[i] <= nums[\result]);
    //@ ensures (\result != -1) ==> (\forall int i; 0 <= i && i < nums.length; nums[\result] >= nums[i]);
    public static int dominantIndex(int[] nums) {
        int biggest_index = 0;

        //@ maintaining 0 <= biggest_index && biggest_index < nums.length;
        //@ maintaining (\forall int j; 0 <= j && j < i; nums[biggest_index] >= nums[j]);
        //@ decreases nums.length - i;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] > nums[biggest_index])
                biggest_index = i;
        }

        //@ maintaining 0 <= biggest_index && biggest_index < nums.length;
        //@ maintaining (\forall int j; 0 <= j && j < i; j != biggest_index ==> 2 * nums[j] <= nums[biggest_index]);
        //@ decreases nums.length - i;
        for (int i = 0; i < nums.length; i++) {
            //@ assume 0 <= i && i < nums.length;
            //@ assume 0 <= biggest_index && biggest_index < nums.length;
            if (i != biggest_index && 2 * nums[i] > nums[biggest_index])
                return -1;
        }

        return biggest_index;
    }
}
