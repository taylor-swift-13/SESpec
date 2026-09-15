#include <limits.h>

/*@ requires nums_len >= 0;
  requires \valid_read(nums + (0 .. nums_len - 1));
  assigns \nothing;
  ensures 0 <= \result < nums_len ==> \forall integer k; 0 <= k < nums_len ==> nums[k] <= nums[\result];
  ensures 0 <= \result < nums_len ==> \forall integer k; 0 <= k < nums_len && k != \result ==> 2 * nums[k] <= nums[\result];
  ensures \result == -1 ==> \true;
  ensures \result == -1 ==> \forall integer k; 0 <= k < nums_len ==> (\exists integer m; 0 <= m < nums_len && m != k && 2 * nums[m] > nums[k]) ==> \true;
  ensures \result >= -1;
  ensures \result == -1 || nums_len == 0 || 0 <= \result < nums_len; */
int stub_A(int * nums, int nums_len);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int stub_B(int * nums, int nums_len);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int check_A_implies_B(int * nums, int nums_len) {
    return stub_A(nums, nums_len);
}

/*@ requires nums_len >= 0;
  requires \valid_read(nums + (0 .. nums_len - 1));
  assigns \nothing;
  ensures 0 <= \result < nums_len ==> \forall integer k; 0 <= k < nums_len ==> nums[k] <= nums[\result];
  ensures 0 <= \result < nums_len ==> \forall integer k; 0 <= k < nums_len && k != \result ==> 2 * nums[k] <= nums[\result];
  ensures \result == -1 ==> \true;
  ensures \result == -1 ==> \forall integer k; 0 <= k < nums_len ==> (\exists integer m; 0 <= m < nums_len && m != k && 2 * nums[m] > nums[k]) ==> \true;
  ensures \result >= -1;
  ensures \result == -1 || nums_len == 0 || 0 <= \result < nums_len; */
int check_B_implies_A(int * nums, int nums_len) {
    return stub_B(nums, nums_len);
}
