void foo56_helper1_c133(int * nums, int nums_len);
void foo133(int * nums, int nums_len, int left, int right);


void foo133(int * nums, int nums_len, int left, int right) {

        int temp = nums[left];
        nums[left] = nums[right];
        nums[right] = temp;
}