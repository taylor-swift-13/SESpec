
/*@
  logic integer max_in_range(int* nums, integer lo, integer hi) =
    lo >= hi ? nums[lo] : (nums[hi - 1] > max_in_range(nums, lo, hi - 1) ? nums[hi - 1] : max_in_range(nums, lo, hi - 1));

  logic integer min_in_range(int* nums, integer lo, integer hi) =
    lo >= hi ? nums[lo] : (nums[hi - 1] < min_in_range(nums, lo, hi - 1) ? nums[hi - 1] : min_in_range(nums, lo, hi - 1));
*/

/*@
  requires nums_len > 0 && nums_len < 100;
  requires \valid(nums + (0 .. nums_len - 1));
  ensures \result == max_in_range(nums, 0, nums_len) - min_in_range(nums, 0, nums_len);
*/
int foo101(int * nums, int nums_len) {

    int max = nums[0];
    int min = nums[0];
    
    /*@
      loop invariant 1 <= i <= nums_len;
      loop invariant max == max_in_range(nums, 0, i);
      loop invariant min == min_in_range(nums, 0, i);
      loop invariant nums_len == \at(nums_len,Pre);
      loop invariant nums == \at(nums,Pre);
      loop assigns i, max, min;
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
