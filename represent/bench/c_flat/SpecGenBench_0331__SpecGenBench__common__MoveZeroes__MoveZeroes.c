void moveZeroes(int * nums, int nums_len);
void swap(int * nums, int nums_len, int left, int right);

void moveZeroes(int * nums, int nums_len) {

        int n = nums_len, left = 0, right = 0;
        while (right < n) {
            if (nums[right] != 0) {
                swap(nums, nums_len, left, right);
                left++;
            }
            right++;
        }
}

void swap(int * nums, int nums_len, int left, int right) {

        int temp = nums[left];
        nums[left] = nums[right];
        nums[right] = temp;
}
