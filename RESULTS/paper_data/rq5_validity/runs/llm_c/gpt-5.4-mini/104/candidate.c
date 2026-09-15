/*@
    requires nums_len > 0;
    requires \valid_read(nums + (0 .. nums_len - 1));
    assigns \nothing;
    ensures 0 <= \result < nums_len || \result == -1;
    ensures \result == -1 ==> \exists integer i; 0 <= i < nums_len &&
                              (\forall integer j; 0 <= j < nums_len && j != i ==> 2 * nums[j] <= nums[i]);
    ensures \result != -1 ==> (\forall integer j; 0 <= j < nums_len && j != \result ==> 2 * nums[j] <= nums[\result]);
*/
int dominantIndex(int * nums, int nums_len);

int dominantIndex(int * nums, int nums_len) {

        int biggest_index = 0;

        /*@
            loop invariant 0 <= i <= nums_len;
            loop invariant 0 <= biggest_index < nums_len;
            loop invariant \forall integer j; 0 <= j < i ==> nums[biggest_index] >= nums[j];
            loop assigns i, biggest_index;
            loop variant nums_len - i;
        */
        for (int i = 0; i < nums_len; i++) {
            if (nums[i] > nums[biggest_index])
                biggest_index = i;
        }

        /*@
            loop invariant 0 <= i <= nums_len;
            loop invariant 0 <= biggest_index < nums_len;
            loop invariant \forall integer k; 0 <= k < nums_len && k != biggest_index && k < i ==> 2 * nums[k] <= nums[biggest_index];
            loop assigns i;
            loop variant nums_len - i;
        */
        for (int i = 0; i < nums_len; i++) {
            if (i != biggest_index && 2 * nums[i] > nums[biggest_index])
                return -1;
        }

        return biggest_index;
}
