
/*@
  requires nums_len > 0;
  requires \valid_read(nums + (0 .. nums_len-1));
  assigns \nothing;
  ensures \result >= 0;
  ensures \forall integer i, j;
            0 <= i < nums_len && 0 <= j < nums_len ==> \result >= nums[i] - nums[j];
*/
int foo242(int *nums, int nums_len) {
    int max = nums[0];
    int min = nums[0];

    /*@
      loop invariant 1 <= i <= nums_len;
      loop invariant \forall integer j; 0 <= j < i ==> nums[j] <= max;
      loop invariant \forall integer j; 0 <= j < i ==> nums[j] >= min;
      loop invariant max >= nums[0];
      loop invariant min <= nums[0];
      loop invariant max >= min;
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
