
/*@
  logic integer slice_max(int* a, integer lo, integer hi) =
    lo >= hi ? -2147483648
             : (a[hi-1] > slice_max(a, lo, hi-1) ? a[hi-1] : slice_max(a, lo, hi-1));
*/

/*@
  logic integer slice_min(int* a, integer lo, integer hi) =
    lo >= hi ? 2147483647
             : (a[hi-1] < slice_min(a, lo, hi-1) ? a[hi-1] : slice_min(a, lo, hi-1));
*/

/*@
  requires nums_len >= 1;
  requires \valid_read(nums + (0 .. nums_len-1));
  assigns \nothing;
*/
int foo242(int * nums, int nums_len) {

    int max = nums[0];
    int min = nums[0];

    /*@
      loop invariant 1 <= i <= nums_len;
      loop invariant max == slice_max(nums, 0, i);
      loop invariant min == slice_min(nums, 0, i);
      loop invariant \forall integer k; 0 <= k < nums_len ==> nums[k] == \at(nums[k], Pre);
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
