void moveZeroes(int * nums, int nums_len);
void swap(int * nums, int nums_len, int left, int right);

/*@
    requires nums_len >= 0;
    requires \valid(nums + (0 .. nums_len-1));
    assigns nums[0..nums_len-1];
    /* All zeros are placed after all non-zeros in the result. */
    ensures \forall integer i, j; 0 <= i < nums_len && 0 <= j < nums_len && i < j ==> (nums[i] == 0 ==> nums[j] == 0);
    /* Every non-zero value in the result appears somewhere in the original array. */
    ensures \forall integer i; 0 <= i < nums_len && nums[i] != 0 ==> (\exists integer j; 0 <= j < nums_len && \old(nums[j]) == nums[i]);
    /* Every non-zero value of the original array appears somewhere in the result. */
    ensures \forall integer j; 0 <= j < nums_len && \old(nums[j]) != 0 ==> (\exists integer i; 0 <= i < nums_len && nums[i] == \old(nums[j]));
*/
void moveZeroes(int * nums, int nums_len) {

        int n = nums_len, left = 0, right = 0;
        /*@
            loop invariant 0 <= left <= right <= n;
            loop invariant \forall integer k; 0 <= k < left ==> nums[k] != 0;
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
    requires nums_len >= 0;
    requires \valid(nums + (0 .. nums_len-1));
    requires 0 <= left < nums_len;
    requires 0 <= right < nums_len;
    assigns nums[left], nums[right];
    ensures nums[left] == \old(nums[right]);
    ensures nums[right] == \old(nums[left]);
    ensures \forall integer k; 0 <= k < nums_len && k != left && k != right ==> nums[k] == \old(nums[k]);
*/
void swap(int * nums, int nums_len, int left, int right) {

        int temp = nums[left];
        nums[left] = nums[right];
        nums[right] = temp;
}
