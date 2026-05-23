/*@
    requires \valid(nums+(0..nums_len-1));
    requires nums_len > 0;
    ensures \forall integer i; 0 <= i < nums_len ==> \exists integer j; 0 <= j < nums_len && nums[j] >= nums[i];
    ensures \forall integer i; 0 <= i < nums_len ==> \exists integer j; 0 <= j < nums_len && nums[j] <= nums[i];
    ensures \result == (\max(0, nums_len-1, nums) - \min(0, nums_len-1, nums));
    assigns \nothing;
*/
int bigDiff(int * nums, int nums_len) {

        int max = nums[0];
        int min = nums[0];
        /*@
            loop invariant 1 <= i <= nums_len;
            loop invariant \forall integer j; 0 <= j < i ==> max >= nums[j];
            loop invariant \forall integer j; 0 <= j < i ==> min <= nums[j];
            loop assigns i, max, min;
            loop variant nums_len - i;
        */
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
