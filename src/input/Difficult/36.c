void foo56_helper1(int *nums, int nums_len);
void foo56(int *nums, int nums_len, int left, int right);

void foo56_helper1(int *nums, int nums_len) {
    int n = nums_len;
    int left = 0;
    int right = 0;

    while (right < n) {
        if (nums[right] != 0) {
            foo56(nums, nums_len, left, right);
            left++;
        }
        right++;
    }
}

void foo56(int *nums, int nums_len, int left, int right) {
    int temp = nums[left];
    nums[left] = nums[right];
    nums[right] = temp;
}
