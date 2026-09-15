/*@
    requires \valid(nums + (0..nums_len-1));
    assigns nums[0..nums_len-1];
    ensures \forall integer i, j; 0 <= i < j < nums_len && nums[j] != 0 ==> nums[i] != 0;
    ensures \forall integer i; 0 <= i < nums_len && nums[i] == 0 ==> 
             \forall integer j; i <= j < nums_len ==> nums[j] == 0;
*/
void moveZeroes(int * nums, int nums_len) {

        int n = nums_len, left = 0, right = 0;
        /*@
            loop invariant 0 <= right <= n;
            loop invariant 0 <= left <= right;
            loop invariant \forall integer i; 0 <= i < left ==> nums[i] != 0;
            loop invariant \forall integer i; left <= i < right ==> nums[i] == 0;
            loop assigns left, right, nums[0..nums_len-1];
            loop variant n - right;
        */
        while (right < n) {
            if (nums[right] != 0) {
                swap(nums, nums_len, left, right);
                left++;
            }
            right++;
        }
}

/*@
    requires \valid(nums + (0..nums_len-1));
    requires 0 <= left < nums_len;
    requires 0 <= right < nums_len;
    assigns nums[left], nums[right];
    ensures nums[left] == \old(nums[right]);
    ensures nums[right] == \old(nums[left]);
*/
void swap(int * nums, int nums_len, int left, int right) {

        int temp = nums[left];
        nums[left] = nums[right];
        nums[right] = temp;
}
