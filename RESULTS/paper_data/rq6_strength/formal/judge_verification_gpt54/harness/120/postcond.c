#include <limits.h>

/*@ requires nums_len >= 0;
  requires \valid(&nums[0] + (0..nums_len-1));
  requires \forall integer i; 0 <= i < nums_len ==> 0 <= nums[i] <= 100;
  assigns \nothing;
  ensures \result == 0 || \result == 1;
  ensures \result == 1 ==> (\forall integer k; 0 <= k < nums_len - 1 ==> nums[k] <= nums[k+1]) || (\forall integer k; 0 <= k < nums_len - 1 ==> nums[k] >= nums[k+1]);
  ensures \result == 0 ==> \true; */
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
  requires \valid(&nums[0] + (0..nums_len-1));
  requires \forall integer i; 0 <= i < nums_len ==> 0 <= nums[i] <= 100;
  assigns \nothing;
  ensures \result == 0 || \result == 1;
  ensures \result == 1 ==> (\forall integer k; 0 <= k < nums_len - 1 ==> nums[k] <= nums[k+1]) || (\forall integer k; 0 <= k < nums_len - 1 ==> nums[k] >= nums[k+1]);
  ensures \result == 0 ==> \true; */
int check_B_implies_A(int * nums, int nums_len) {
    return stub_B(nums, nums_len);
}
