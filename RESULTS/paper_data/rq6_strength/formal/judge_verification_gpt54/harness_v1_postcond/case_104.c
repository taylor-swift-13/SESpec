#include <limits.h>



/*@requires nums_len >= 0;
  requires \valid_read(nums + (0 .. nums_len - 1));
  assigns \nothing;
  ensures 0 <= \result < nums_len ==> \forall integer k; 0 <= k < nums_len ==> nums[k] <= nums[\result];
  ensures 0 <= \result < nums_len ==> \forall integer k; 0 <= k < nums_len && k != \result ==> 2 * nums[k] <= nums[\result];
  ensures \result == -1 ==> \true;
  ensures \result == -1 ==> \forall integer k; 0 <= k < nums_len ==> (\exists integer m; 0 <= m < nums_len && m != k && 2 * nums[m] > nums[k]) ==> \true;
  ensures \result >= -1;
  ensures \result == -1 || nums_len == 0 || 0 <= \result < nums_len;*/
int stub_A(int * nums, int nums_len);

/*@loop invariant i > 0 ==> nums[biggest_index] >= nums[0];
        loop invariant i == 0 || nums[biggest_index] >= nums[i-1];
        loop invariant biggest_index == 0 || nums[biggest_index] >= nums[biggest_index];
        loop invariant biggest_index == 0 || nums[biggest_index] >= nums[0];
        loop invariant biggest_index == 0 ==> \forall integer k; 0 <= k < i ==> nums[0] >= nums[k];
        loop invariant \forall integer k; 0 <= k < nums_len ==> nums[biggest_index] >= nums[k];
        loop invariant \forall integer k; 0 <= k < nums_len ==> nums[biggest_index] >= nums[k] || 2 * nums[k] <= nums[biggest_index];
        loop invariant \forall integer k; 0 <= k < i ==> nums[biggest_index] >= nums[k];
        loop invariant \forall integer k; 0 <= k < i ==> k == biggest_index || nums[biggest_index] >= nums[k];
        loop invariant \forall integer k; 0 <= k < i ==> k <= biggest_index || nums[biggest_index] >= nums[k];
        loop invariant \forall integer k; 0 <= k < i ==> k != biggest_index ==> 2 * nums[k] <= nums[biggest_index];
        loop invariant \forall integer k; 0 <= k < i ==> 2 * nums[k] <= nums[biggest_index] || k == biggest_index;
        loop invariant \forall integer k; 0 <= k < i ==> 2 * nums[k] <= 2 * nums[biggest_index];
        loop invariant \forall integer k; 0 <= k < i ==> (k == biggest_index || nums[biggest_index] >= nums[k]);
        loop invariant \forall integer k; 0 <= k < i ==> (k == biggest_index || 2 * nums[k] <= nums[biggest_index]);
        loop invariant \forall integer k; 0 <= k < i ==> (k != biggest_index ==> nums[biggest_index] >= nums[k]);
        loop invariant \forall integer k; 0 <= k < i ==> (k != biggest_index ==> 2 * nums[k] <= nums[biggest_index]);
        loop invariant \forall integer k; 0 <= k < i && k != biggest_index ==> nums[biggest_index] >= nums[k];
        loop invariant \forall integer k; 0 <= k < i && k != biggest_index ==> 2 * nums[k] <= nums[biggest_index];
        loop invariant \exists integer k; 0 <= k < i && biggest_index == k ==> nums[biggest_index] == nums[k];
        loop invariant 0 <= i;
        loop invariant 0 <= biggest_index;
        loop invariant 0 <= biggest_index < nums_len || nums_len <= 0;
        loop assigns nums[0..nums_len-1];
        loop assigns i;
        loop assigns biggest_index;*/
int stub_B(int * nums, int nums_len);

/*@loop invariant i > 0 ==> nums[biggest_index] >= nums[0];
        loop invariant i == 0 || nums[biggest_index] >= nums[i-1];
        loop invariant biggest_index == 0 || nums[biggest_index] >= nums[biggest_index];
        loop invariant biggest_index == 0 || nums[biggest_index] >= nums[0];
        loop invariant biggest_index == 0 ==> \forall integer k; 0 <= k < i ==> nums[0] >= nums[k];
        loop invariant \forall integer k; 0 <= k < nums_len ==> nums[biggest_index] >= nums[k];
        loop invariant \forall integer k; 0 <= k < nums_len ==> nums[biggest_index] >= nums[k] || 2 * nums[k] <= nums[biggest_index];
        loop invariant \forall integer k; 0 <= k < i ==> nums[biggest_index] >= nums[k];
        loop invariant \forall integer k; 0 <= k < i ==> k == biggest_index || nums[biggest_index] >= nums[k];
        loop invariant \forall integer k; 0 <= k < i ==> k <= biggest_index || nums[biggest_index] >= nums[k];
        loop invariant \forall integer k; 0 <= k < i ==> k != biggest_index ==> 2 * nums[k] <= nums[biggest_index];
        loop invariant \forall integer k; 0 <= k < i ==> 2 * nums[k] <= nums[biggest_index] || k == biggest_index;
        loop invariant \forall integer k; 0 <= k < i ==> 2 * nums[k] <= 2 * nums[biggest_index];
        loop invariant \forall integer k; 0 <= k < i ==> (k == biggest_index || nums[biggest_index] >= nums[k]);
        loop invariant \forall integer k; 0 <= k < i ==> (k == biggest_index || 2 * nums[k] <= nums[biggest_index]);
        loop invariant \forall integer k; 0 <= k < i ==> (k != biggest_index ==> nums[biggest_index] >= nums[k]);
        loop invariant \forall integer k; 0 <= k < i ==> (k != biggest_index ==> 2 * nums[k] <= nums[biggest_index]);
        loop invariant \forall integer k; 0 <= k < i && k != biggest_index ==> nums[biggest_index] >= nums[k];
        loop invariant \forall integer k; 0 <= k < i && k != biggest_index ==> 2 * nums[k] <= nums[biggest_index];
        loop invariant \exists integer k; 0 <= k < i && biggest_index == k ==> nums[biggest_index] == nums[k];
        loop invariant 0 <= i;
        loop invariant 0 <= biggest_index;
        loop invariant 0 <= biggest_index < nums_len || nums_len <= 0;
        loop assigns nums[0..nums_len-1];
        loop assigns i;
        loop assigns biggest_index;*/
int check_A_implies_B(int * nums, int nums_len) {
    return stub_A(nums, nums_len);
}

/*@requires nums_len >= 0;
  requires \valid_read(nums + (0 .. nums_len - 1));
  assigns \nothing;
  ensures 0 <= \result < nums_len ==> \forall integer k; 0 <= k < nums_len ==> nums[k] <= nums[\result];
  ensures 0 <= \result < nums_len ==> \forall integer k; 0 <= k < nums_len && k != \result ==> 2 * nums[k] <= nums[\result];
  ensures \result == -1 ==> \true;
  ensures \result == -1 ==> \forall integer k; 0 <= k < nums_len ==> (\exists integer m; 0 <= m < nums_len && m != k && 2 * nums[m] > nums[k]) ==> \true;
  ensures \result >= -1;
  ensures \result == -1 || nums_len == 0 || 0 <= \result < nums_len;*/
int check_B_implies_A(int * nums, int nums_len) {
    return stub_B(nums, nums_len);
}
