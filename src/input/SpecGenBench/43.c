int foo43(int * nums, int nums_len);

int foo43(int * nums, int nums_len) {

        int inc = 1, dec = 1;
        int n = nums_len;
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] > nums[i + 1]) {
                inc = 0;
            }
            if (nums[i] < nums[i + 1]) {
                dec = 0;
            }
        }
        return inc || dec;
}
