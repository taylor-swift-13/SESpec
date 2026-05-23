#include <limits.h>

/*@ requires (0 <= i <= nums_len) && (0 <= biggest_index <= i) && (i == 0 ==> biggest_index == 0) && (i > 0 ==> 0 <= biggest_index < i) && (i > 0 ==> \forall integer k; 0 <= k < i ==> nums[k] <= nums[biggest_index]) && (i > 0 ==> \exists integer k; 0 <= k < i && nums[k] == nums[biggest_index]) && (nums_len == \at(nums_len,Pre)) && (nums == \at(nums,Pre)) && (\forall integer k; 0 <= k < nums_len ==> nums[k] == \at(nums[k], Pre));
    assigns \nothing;
*/
void check_A_implies_B(int biggest_index, int i, int k, int *nums, int nums_len) {
    /*@ assert (i == 0 || nums[biggest_index] >= nums[i-1]); */
    /*@ assert (i == 0 ==> biggest_index == 0); */
    /*@ assert (biggest_index == 0 || nums[biggest_index] >= nums[0]); */
    /*@ assert (biggest_index == 0 || \exists integer k; 0 <= k < i && k == biggest_index); */
    /*@ assert (biggest_index == 0 ==> \forall integer k; 0 <= k < i ==> nums[0] >= nums[k]); */
    /*@ assert (biggest_index <= i); */
    /*@ assert (biggest_index <= i || i == 0); */
    /*@ assert (biggest_index < i || i == 0); */
    /*@ assert (biggest_index < i || biggest_index == 0); */
    /*@ assert (\forall integer k; 0 <= k < i ==> nums[biggest_index] >= nums[k]); */
    /*@ assert (\forall integer k; 0 <= k < i ==> k == biggest_index || nums[biggest_index] >= nums[k]); */
    /*@ assert (\forall integer k; 0 <= k < i ==> k <= biggest_index || nums[biggest_index] >= nums[k]); */
    /*@ assert (\forall integer k; 0 <= k < i ==> k != biggest_index ==> nums[biggest_index] >= nums[k]); */
    /*@ assert (\forall integer k; 0 <= k < i ==> biggest_index == 0 || nums[biggest_index] >= nums[0]); */
    /*@ assert (\forall integer k; 0 <= k < i ==> (k == biggest_index || nums[biggest_index] >= nums[k])); */
    /*@ assert (\forall integer k; 0 <= k < i ==> (k != biggest_index ==> nums[biggest_index] >= nums[k])); */
    /*@ assert (\forall integer k; 0 <= k < i && k != biggest_index ==> nums[biggest_index] >= nums[k]); */
    /*@ assert (\exists integer k; 0 <= k <= i && biggest_index == k && nums[biggest_index] == nums[k]); */
    /*@ assert (\exists integer k; 0 <= k < i+1 && nums[biggest_index] == nums[k]); */
    /*@ assert (\exists integer k; 0 <= k < i+1 && k == biggest_index); */
    /*@ assert (\exists integer k; 0 <= k < i+1 && k == biggest_index && nums[k] == nums[biggest_index]); */
    /*@ assert (\exists integer k; 0 <= k < i+1 && k == biggest_index && nums[biggest_index] == nums[k]); */
    /*@ assert (\exists integer k; 0 <= k < i+1 && biggest_index == k && nums[biggest_index] == nums[k]); */
    /*@ assert (\exists integer k; 0 <= k < i && biggest_index == k ==> nums[biggest_index] == nums[k]); */
    /*@ assert (0 <= i); */
    /*@ assert (0 <= biggest_index); */
    /*@ assert (0 <= biggest_index < nums_len || nums_len <= 0); */
}

/*@ requires (i == 0 || nums[biggest_index] >= nums[i-1]) && (i == 0 ==> biggest_index == 0) && (biggest_index == 0 || nums[biggest_index] >= nums[0]) && (biggest_index == 0 || \exists integer k; 0 <= k < i && k == biggest_index) && (biggest_index == 0 ==> \forall integer k; 0 <= k < i ==> nums[0] >= nums[k]) && (biggest_index <= i) && (biggest_index <= i || i == 0) && (biggest_index < i || i == 0) && (biggest_index < i || biggest_index == 0) && (\forall integer k; 0 <= k < i ==> nums[biggest_index] >= nums[k]) && (\forall integer k; 0 <= k < i ==> k == biggest_index || nums[biggest_index] >= nums[k]) && (\forall integer k; 0 <= k < i ==> k <= biggest_index || nums[biggest_index] >= nums[k]) && (\forall integer k; 0 <= k < i ==> k != biggest_index ==> nums[biggest_index] >= nums[k]) && (\forall integer k; 0 <= k < i ==> biggest_index == 0 || nums[biggest_index] >= nums[0]) && (\forall integer k; 0 <= k < i ==> (k == biggest_index || nums[biggest_index] >= nums[k])) && (\forall integer k; 0 <= k < i ==> (k != biggest_index ==> nums[biggest_index] >= nums[k])) && (\forall integer k; 0 <= k < i && k != biggest_index ==> nums[biggest_index] >= nums[k]) && (\exists integer k; 0 <= k <= i && biggest_index == k && nums[biggest_index] == nums[k]) && (\exists integer k; 0 <= k < i+1 && nums[biggest_index] == nums[k]) && (\exists integer k; 0 <= k < i+1 && k == biggest_index) && (\exists integer k; 0 <= k < i+1 && k == biggest_index && nums[k] == nums[biggest_index]) && (\exists integer k; 0 <= k < i+1 && k == biggest_index && nums[biggest_index] == nums[k]) && (\exists integer k; 0 <= k < i+1 && biggest_index == k && nums[biggest_index] == nums[k]) && (\exists integer k; 0 <= k < i && biggest_index == k ==> nums[biggest_index] == nums[k]) && (0 <= i) && (0 <= biggest_index) && (0 <= biggest_index < nums_len || nums_len <= 0);
    assigns \nothing;
*/
void check_B_implies_A(int biggest_index, int i, int k, int *nums, int nums_len) {
    /*@ assert (0 <= i <= nums_len); */
    /*@ assert (0 <= biggest_index <= i); */
    /*@ assert (i == 0 ==> biggest_index == 0); */
    /*@ assert (i > 0 ==> 0 <= biggest_index < i); */
    /*@ assert (i > 0 ==> \forall integer k; 0 <= k < i ==> nums[k] <= nums[biggest_index]); */
    /*@ assert (i > 0 ==> \exists integer k; 0 <= k < i && nums[k] == nums[biggest_index]); */
    /*@ assert (nums_len == \at(nums_len,Pre)); */
    /*@ assert (nums == \at(nums,Pre)); */
    /*@ assert (\forall integer k; 0 <= k < nums_len ==> nums[k] == \at(nums[k], Pre)); */
}
