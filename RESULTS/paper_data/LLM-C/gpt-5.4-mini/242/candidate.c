/*@ 
    requires nums_len > 0;
    requires \valid_read(nums + (0 .. nums_len - 1));
    assigns \nothing;
    ensures \result == (\max(0, nums_len-1, \lambda integer i; nums[i])) - (\min(0, nums_len-1, \lambda integer i; nums[i]));
*/
int bigDiff(int * nums, int nums_len);

 /*@ 
    requires nums_len > 0;
    requires \valid_read(nums + (0 .. nums_len - 1));
    assigns \nothing;
    ensures \result == (\max(0, nums_len-1, \lambda integer i; nums[i])) - (\min(0, nums_len-1, \lambda integer i; nums[i]));
*/
int bigDiff(int * nums, int nums_len) {

        int max = nums[0];
        int min = nums[0];
        /*@
            loop invariant 1 <= i <= nums_len;
            loop invariant \forall integer j; 0 <= j < i ==> min <= nums[j] <= max;
            loop invariant \exists integer j; 0 <= j < i && nums[j] == max;
            loop invariant \exists integer j; 0 <= j < i && nums[j] == min;
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
