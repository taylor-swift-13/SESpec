int bigDiff(int * nums, int nums_len);

int bigDiff(int * nums, int nums_len) {

        int max = nums[0];
        int min = nums[0];
        for (int i = 1; i < nums_len; i++) {
            if (nums[i] > max) {
                max = nums[i];
            }
            if (nums[i] < min) {
                min = nums[i];
            }
        }
        return max - min;
}
