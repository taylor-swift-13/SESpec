
/*@
  logic integer max_index(int* nums, integer len) =
    len <= 0 ? 0 : (nums[len - 1] > nums[max_index(nums, len - 1)] ? len - 1 : max_index(nums, len - 1));
*/

/*@
  logic integer count_doubled_elements(int* nums, integer len, integer max_idx) =
    len <= 0 ? 0 : count_doubled_elements(nums, len - 1, max_idx) + 
                  ((len - 1 != max_idx && 2 * nums[len - 1] > nums[max_idx]) ? 1 : 0);
*/

/*@
  requires \valid(nums + (0..nums_len-1));
  requires nums_len > 0;
  requires \forall integer i; 0 <= i < nums_len ==> nums[i] >= 0; // Ensure all elements are non-negative
  assigns \nothing;
  ensures \result != -1 ==> \forall integer i; 0 <= i < nums_len && i != \result ==> nums[i] <= nums[\result];
*/
int foo104(int * nums, int nums_len) {

    int biggest_index = 0;

    /*@
      loop invariant 0 <= i <= nums_len;
      loop invariant 0 <= biggest_index < nums_len;
      loop invariant \forall integer k; 0 <= k < i ==> nums[biggest_index] >= nums[k];
      loop invariant nums_len == \at(nums_len, Pre);
      loop invariant nums == \at(nums, Pre);
      loop assigns i, biggest_index;
    */
    for (int i = 0; i < nums_len; i++) {
        if (nums[i] > nums[biggest_index])
            biggest_index = i;
    }

    /*@
      loop invariant 0 <= i <= nums_len;
      loop invariant \forall integer k; 0 <= k < nums_len ==> nums[k] == \at(nums[k], Pre);
      loop invariant \forall integer k; 0 <= k < nums_len && k != biggest_index ==> nums[k] <= nums[biggest_index];
      loop invariant \forall integer k; 0 <= k < i && k != biggest_index ==> 2 * nums[k] <= nums[biggest_index];
      loop assigns i;
    */
    for (int i = 0; i < nums_len; i++) {
        if (i != biggest_index && 2 * nums[i] > nums[biggest_index])
            return -1;
    }

    return biggest_index;
}
