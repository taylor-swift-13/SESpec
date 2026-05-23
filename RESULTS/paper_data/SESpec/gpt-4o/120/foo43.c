
/*@
  logic integer count_gt(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_gt(a, lo, hi - 1, v) + (a[hi - 1] > v ? 1 : 0);

  logic integer count_lt(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_lt(a, lo, hi - 1, v) + (a[hi - 1] < v ? 1 : 0);
*/

/*@
  requires \valid(nums + (0 .. nums_len - 1));
  requires nums_len > 0 && nums_len < 100;
  assigns \nothing;
  ensures \result == 1 ==> (\forall integer k; 0 <= k < nums_len - 1 ==> nums[k] <= nums[k + 1] || nums[k] >= nums[k + 1]);
*/
int foo43(int * nums, int nums_len) {

    int inc = 1, dec = 1;
    int n = nums_len;

    /*@
      loop invariant 0 <= i <= n - 1;
      loop invariant inc == 1 ==> (\forall integer k; 0 <= k < i ==> nums[k] <= nums[k + 1]);
      loop invariant dec == 1 ==> (\forall integer k; 0 <= k < i ==> nums[k] >= nums[k + 1]);
      loop invariant inc == 0 || (\forall integer k; 0 <= k < i ==> nums[k] <= nums[k + 1]);
      loop invariant dec == 0 || (\forall integer k; 0 <= k < i ==> nums[k] >= nums[k + 1]);
      loop invariant n == \at(nums_len,Pre);
      loop invariant nums_len == \at(nums_len,Pre);
      loop invariant nums == \at(nums,Pre);
      loop assigns i, inc, dec;
      loop variant n - 1 - i;
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
