#include <limits.h>

/*@ requires (0 <= i <= nums_len) && (0 <= biggest_index <= nums_len) && (\forall integer k; 0 <= k < i ==> (k == biggest_index || 2 * nums[k] <= nums[biggest_index])) && (\forall integer k; 0 <= k < nums_len ==> nums[k] == \at(nums[k], Pre));
    assigns \nothing;
*/
void check_A_implies_B(int biggest_index, int i, int k, int *nums, int nums_len) {
    /*@ assert (i > 0 ==> nums[biggest_index] >= nums[0]); */
    /*@ assert (i == 0 || nums[biggest_index] >= nums[i-1]); */
    /*@ assert (biggest_index == 0 || nums[biggest_index] >= nums[biggest_index]); */
    /*@ assert (biggest_index == 0 || nums[biggest_index] >= nums[0]); */
    /*@ assert (biggest_index == 0 ==> \forall integer k; 0 <= k < i ==> nums[0] >= nums[k]); */
    /*@ assert (\forall integer k; 0 <= k < nums_len ==> nums[biggest_index] >= nums[k]); */
    /*@ assert (\forall integer k; 0 <= k < nums_len ==> nums[biggest_index] >= nums[k] || 2 * nums[k] <= nums[biggest_index]); */
    /*@ assert (\forall integer k; 0 <= k < i ==> nums[biggest_index] >= nums[k]); */
    /*@ assert (\forall integer k; 0 <= k < i ==> k == biggest_index || nums[biggest_index] >= nums[k]); */
    /*@ assert (\forall integer k; 0 <= k < i ==> k <= biggest_index || nums[biggest_index] >= nums[k]); */
    /*@ assert (\forall integer k; 0 <= k < i ==> k != biggest_index ==> 2 * nums[k] <= nums[biggest_index]); */
    /*@ assert (\forall integer k; 0 <= k < i ==> 2 * nums[k] <= nums[biggest_index] || k == biggest_index); */
    /*@ assert (\forall integer k; 0 <= k < i ==> 2 * nums[k] <= 2 * nums[biggest_index]); */
    /*@ assert (\forall integer k; 0 <= k < i ==> (k == biggest_index || nums[biggest_index] >= nums[k])); */
    /*@ assert (\forall integer k; 0 <= k < i ==> (k == biggest_index || 2 * nums[k] <= nums[biggest_index])); */
    /*@ assert (\forall integer k; 0 <= k < i ==> (k != biggest_index ==> nums[biggest_index] >= nums[k])); */
    /*@ assert (\forall integer k; 0 <= k < i ==> (k != biggest_index ==> 2 * nums[k] <= nums[biggest_index])); */
    /*@ assert (\forall integer k; 0 <= k < i && k != biggest_index ==> nums[biggest_index] >= nums[k]); */
    /*@ assert (\forall integer k; 0 <= k < i && k != biggest_index ==> 2 * nums[k] <= nums[biggest_index]); */
    /*@ assert (\exists integer k; 0 <= k < i && biggest_index == k ==> nums[biggest_index] == nums[k]); */
    /*@ assert (0 <= i); */
    /*@ assert (0 <= biggest_index); */
    /*@ assert (0 <= biggest_index < nums_len || nums_len <= 0); */
}

/*@ requires (i > 0 ==> nums[biggest_index] >= nums[0]) && (i == 0 || nums[biggest_index] >= nums[i-1]) && (biggest_index == 0 || nums[biggest_index] >= nums[biggest_index]) && (biggest_index == 0 || nums[biggest_index] >= nums[0]) && (biggest_index == 0 ==> \forall integer k; 0 <= k < i ==> nums[0] >= nums[k]) && (\forall integer k; 0 <= k < nums_len ==> nums[biggest_index] >= nums[k]) && (\forall integer k; 0 <= k < nums_len ==> nums[biggest_index] >= nums[k] || 2 * nums[k] <= nums[biggest_index]) && (\forall integer k; 0 <= k < i ==> nums[biggest_index] >= nums[k]) && (\forall integer k; 0 <= k < i ==> k == biggest_index || nums[biggest_index] >= nums[k]) && (\forall integer k; 0 <= k < i ==> k <= biggest_index || nums[biggest_index] >= nums[k]) && (\forall integer k; 0 <= k < i ==> k != biggest_index ==> 2 * nums[k] <= nums[biggest_index]) && (\forall integer k; 0 <= k < i ==> 2 * nums[k] <= nums[biggest_index] || k == biggest_index) && (\forall integer k; 0 <= k < i ==> 2 * nums[k] <= 2 * nums[biggest_index]) && (\forall integer k; 0 <= k < i ==> (k == biggest_index || nums[biggest_index] >= nums[k])) && (\forall integer k; 0 <= k < i ==> (k == biggest_index || 2 * nums[k] <= nums[biggest_index])) && (\forall integer k; 0 <= k < i ==> (k != biggest_index ==> nums[biggest_index] >= nums[k])) && (\forall integer k; 0 <= k < i ==> (k != biggest_index ==> 2 * nums[k] <= nums[biggest_index])) && (\forall integer k; 0 <= k < i && k != biggest_index ==> nums[biggest_index] >= nums[k]) && (\forall integer k; 0 <= k < i && k != biggest_index ==> 2 * nums[k] <= nums[biggest_index]) && (\exists integer k; 0 <= k < i && biggest_index == k ==> nums[biggest_index] == nums[k]) && (0 <= i) && (0 <= biggest_index) && (0 <= biggest_index < nums_len || nums_len <= 0);
    assigns \nothing;
*/
void check_B_implies_A(int biggest_index, int i, int k, int *nums, int nums_len) {
    /*@ assert (0 <= i <= nums_len); */
    /*@ assert (0 <= biggest_index <= nums_len); */
    /*@ assert (\forall integer k; 0 <= k < i ==> (k == biggest_index || 2 * nums[k] <= nums[biggest_index])); */
    /*@ assert (\forall integer k; 0 <= k < nums_len ==> nums[k] == \at(nums[k], Pre)); */
}
