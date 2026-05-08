int foo233(int * nums, int nums_len);

int foo233(int * nums, int nums_len) {

        int even = 0;
        for (int i = 0; i < nums_len; i++) {
            if (nums[i] % 2 == 0) {
                even = nums[i];
                break;
            }
        }
        return even;
}
