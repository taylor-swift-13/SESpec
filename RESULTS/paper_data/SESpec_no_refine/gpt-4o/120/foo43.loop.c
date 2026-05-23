
/*@
  logic integer count_increasing(int* nums, integer lo, integer hi) =
    lo >= hi - 1 ? 1 : (nums[lo] <= nums[lo + 1] ? count_increasing(nums, lo + 1, hi) : 0);

  logic integer count_decreasing(int* nums, integer lo, integer hi) =
    lo >= hi - 1 ? 1 : (nums[lo] >= nums[lo + 1] ? count_decreasing(nums, lo + 1, hi) : 0);
*/

/*@
  requires \at(nums_len,Pre) > 0 && \at(nums_len,Pre) < 100;
  requires \valid(nums + (0..\at(nums_len,Pre)-1));
  ensures \result == 1 ==> (\forall integer k; 0 <= k < \at(nums_len,Pre) - 1 ==> nums[k] <= nums[k + 1] || nums[k] >= nums[k + 1]);
  ensures \result == 0 ==> (\exists integer k; 0 <= k < \at(nums_len,Pre) - 1 && nums[k] > nums[k + 1] && nums[k] < nums[k + 1]);
*/
int foo43(int * nums, int nums_len) {

    int inc = 1, dec = 1;
    int n = nums_len;

    /*@
      loop invariant 0 <= i <= n - 1;
      loop invariant n == \at(nums_len,Pre);
      loop invariant nums_len == \at(nums_len,Pre);
      loop invariant nums == \at(nums,Pre);
      loop invariant \forall integer k; 0 <= k < i ==> nums[k] == \at(nums[k],Pre);
      loop assigns i, inc, dec;
    */
    for (int i = 0; i < n - 1; ++i) {
        if (nums[i] > nums[i + 1]) {
            inc = 0;
        }
        if (nums[i] < nums[i + 1]) {
            dec = 0;
        }
    }

    return inc || dec;
}
