#include <limits.h>

/*@ requires (0 <= i) && ((n < 0) || (i <= n)) && (0 <= inc <= 1) && (0 <= dec <= 1) && (n == \at(nums_len,Pre)) && (nums_len == \at(nums_len,Pre)) && (nums == \at(nums,Pre)) && (\forall integer k; 0 <= k < n ==> nums[k] == \at(nums[k],Pre)) && (inc == 1 ==> \forall integer k; 0 <= k < i ==> nums[k] <= nums[k+1]) && (dec == 1 ==> \forall integer k; 0 <= k < i ==> nums[k] >= nums[k+1]) && ((i < \at(nums_len,Pre) - 1) ==> (((n == \at(nums_len,Pre))&&(dec == 1)&&(inc == 1)&&(nums_len == \at(nums_len,Pre))&&(nums == \at(nums,Pre))) || (0 <= inc <= 1))) && ((i < \at(nums_len,Pre) - 1) ==> (((n == \at(nums_len,Pre))&&(dec == 1)&&(inc == 1)&&(nums_len == \at(nums_len,Pre))&&(nums == \at(nums,Pre))) || (0 <= dec <= 1))) && (n == \at(nums_len,Pre)) && (nums_len == \at(nums_len,Pre)) && (nums == \at(nums,Pre)) && (\forall integer k; 0 <= k < n ==> nums[k] == \at(nums[k],Pre));
    assigns \nothing;
*/
void check_A_implies_B(int dec, int i, int inc, int k, int n, int *nums, int nums_len) {
    /*@ assert (dec == 1 && inc == 0 ==> \forall integer k; 0 <= k < i ==> nums[k] >= nums[k+1]); */
    /*@ assert (inc == 1 || inc == 0); */
    /*@ assert (inc == 1 ==> dec == 1 || dec == 0); */
    /*@ assert (inc == 1 ==> dec == 1 || (\exists integer k; 0 <= k < i && nums[k] < nums[k+1])); */
    /*@ assert (inc == 1 ==> \forall integer k; 0 <= k < i ==> nums[k] <= nums[k+1]); */
    /*@ assert (inc == 1 ==> \forall integer k; 0 <= k < i ==> nums[k] <= nums[k + 1]); */
    /*@ assert (inc == 1 ==> (\forall integer k; 0 <= k < i ==> nums[k] <= nums[k+1])); */
    /*@ assert (inc == 1 && dec == 1 ==> \forall integer k; 0 <= k < i ==> nums[k] == nums[k+1]); */
    /*@ assert (inc == 1 && dec == 1 ==> (\forall integer k; 0 <= k < i ==> nums[k] == nums[k+1])); */
    /*@ assert (inc == 1 && dec == 0 ==> \forall integer k; 0 <= k < i ==> nums[k] <= nums[k+1]); */
    /*@ assert (inc == 1 && dec == 0 ==> \exists integer k; 0 <= k < i && nums[k] < nums[k+1]); */
    /*@ assert (inc == 1 && dec == 0 ==> (\forall integer k; 0 <= k < i ==> nums[k] <= nums[k+1])); */
    /*@ assert (inc == 1 && dec == 0 ==> (\exists integer k; 0 <= k < i && nums[k] < nums[k+1])); */
    /*@ assert (inc == 0 || inc == 1); */
    /*@ assert (inc == 0 || dec == 0 || (\forall integer k; 0 <= k < i ==> nums[k] == nums[k+1])); */
    /*@ assert (inc == 0 ==> dec == 1 || dec == 0); */
    /*@ assert (inc == 0 ==> dec == 0 || dec == 1); */
    /*@ assert (inc == 0 ==> \exists integer k; 0 <= k < i && nums[k] > nums[k+1]); */
    /*@ assert (inc == 0 ==> (\exists integer k; 0 <= k < i && nums[k] > nums[k+1])); */
    /*@ assert (inc == 0 ==> (\exists integer k; 0 <= k < i && nums[k] != nums[k+1])); */
    /*@ assert (inc == 0 && dec == 1 ==> \forall integer k; 0 <= k < i ==> nums[k] >= nums[k+1]); */
    /*@ assert (inc == 0 && dec == 1 ==> \exists integer k; 0 <= k < i && nums[k] > nums[k+1]); */
    /*@ assert (inc == 0 && dec == 1 ==> (\forall integer k; 0 <= k < i ==> nums[k] >= nums[k+1])); */
    /*@ assert (inc == 0 && dec == 1 ==> (\exists integer k; 0 <= k < i && nums[k] > nums[k+1])); */
    /*@ assert (inc == 0 && dec == 0 ==> \exists integer k; 0 <= k < i && nums[k] != nums[k+1]); */
    /*@ assert (inc == 0 && dec == 0 ==> (\exists integer k; 0 <= k < i && nums[k] > nums[k+1]) && (\exists integer k; 0 <= k < i && nums[k] < nums[k+1])); */
    /*@ assert (inc == 0 && dec == 0 ==> (\exists integer k; 0 <= k < i && nums[k] < nums[k+1]) && (\exists integer k; 0 <= k < i && nums[k] > nums[k+1])); */
    /*@ assert (inc == 0 && dec == 0 ==> (\exists integer k; 0 <= k < i && nums[k] != nums[k+1])); */
    /*@ assert (i == 0 ==> inc == 1 && dec == 1); */
    /*@ assert (dec == 1 || dec == 0); */
    /*@ assert (dec == 1 ==> inc == 1 || inc == 0); */
    /*@ assert (dec == 1 ==> \forall integer k; 0 <= k < i ==> nums[k] >= nums[k+1]); */
    /*@ assert (dec == 1 ==> \forall integer k; 0 <= k < i ==> nums[k] >= nums[k + 1]); */
    /*@ assert (dec == 1 ==> (\forall integer k; 0 <= k < i ==> nums[k] >= nums[k+1])); */
    /*@ assert (dec == 1 && inc == 0 ==> (\forall integer k; 0 <= k < i ==> nums[k] >= nums[k+1])); */
    /*@ assert (dec == 0 || dec == 1); */
    /*@ assert (dec == 0 ==> inc == 1 || inc == 0); */
    /*@ assert (dec == 0 ==> inc == 0 || inc == 1); */
    /*@ assert (dec == 0 ==> \exists integer k; 0 <= k < i && nums[k] < nums[k+1]); */
    /*@ assert (dec == 0 ==> (\exists integer k; 0 <= k < i && nums[k] < nums[k+1])); */
    /*@ assert (dec == 0 ==> (\exists integer k; 0 <= k < i && nums[k] != nums[k+1])); */
    /*@ assert (\forall integer k; 0 <= k < i ==> (nums[k] > nums[k+1] ==> inc == 0)); */
    /*@ assert (\forall integer k; 0 <= k < i ==> (nums[k] < nums[k+1] ==> dec == 0)); */
    /*@ assert (0 <= i); */
    /*@ assert (0 <= i || n <= 1); */
    /*@ assert ((inc == 1) ==> (\forall integer k; 0 <= k < i ==> nums[k] <= nums[k+1])); */
    /*@ assert ((inc == 1) <==> (\forall integer k; 0 <= k < i ==> nums[k] <= nums[k+1])); */
    /*@ assert ((inc == 1 && dec == 0) ==> (\forall integer k; 0 <= k < i ==> nums[k] <= nums[k+1])); */
    /*@ assert ((inc == 0) ==> (\exists integer k; 0 <= k < i && nums[k] > nums[k+1])); */
    /*@ assert ((inc == 0 || dec == 0) ==> (\exists integer k; 0 <= k < i && nums[k] != nums[k+1])); */
    /*@ assert ((inc == 0 && dec == 1) ==> (\forall integer k; 0 <= k < i ==> nums[k] >= nums[k+1])); */
    /*@ assert ((dec == 1) ==> (\forall integer k; 0 <= k < i ==> nums[k] >= nums[k+1])); */
    /*@ assert ((dec == 1) <==> (\forall integer k; 0 <= k < i ==> nums[k] >= nums[k+1])); */
    /*@ assert ((dec == 0) ==> (\exists integer k; 0 <= k < i && nums[k] < nums[k+1])); */
    /*@ assert ((\forall integer k; 0 <= k < i ==> nums[k] >= nums[k+1]) ==> dec == 1); */
    /*@ assert ((\forall integer k; 0 <= k < i ==> nums[k] > nums[k+1] ==> inc == 0)); */
    /*@ assert ((\forall integer k; 0 <= k < i ==> nums[k] <= nums[k+1]) ==> inc == 1); */
    /*@ assert ((\forall integer k; 0 <= k < i ==> nums[k] < nums[k+1] ==> dec == 0)); */
    /*@ assert ((\forall integer k; 0 <= k < i && nums[k] > nums[k+1] ==> inc == 0)); */
    /*@ assert ((\forall integer k; 0 <= k < i && nums[k] < nums[k+1] ==> dec == 0)); */
    /*@ assert ((\exists integer k; 0 <= k < i && nums[k] > nums[k+1]) ==> inc == 0); */
    /*@ assert ((\exists integer k; 0 <= k < i && nums[k] < nums[k+1]) ==> dec == 0); */
}

/*@ requires (dec == 1 && inc == 0 ==> \forall integer k; 0 <= k < i ==> nums[k] >= nums[k+1]) && (inc == 1 || inc == 0) && (inc == 1 ==> dec == 1 || dec == 0) && (inc == 1 ==> dec == 1 || (\exists integer k; 0 <= k < i && nums[k] < nums[k+1])) && (inc == 1 ==> \forall integer k; 0 <= k < i ==> nums[k] <= nums[k+1]) && (inc == 1 ==> \forall integer k; 0 <= k < i ==> nums[k] <= nums[k + 1]) && (inc == 1 ==> (\forall integer k; 0 <= k < i ==> nums[k] <= nums[k+1])) && (inc == 1 && dec == 1 ==> \forall integer k; 0 <= k < i ==> nums[k] == nums[k+1]) && (inc == 1 && dec == 1 ==> (\forall integer k; 0 <= k < i ==> nums[k] == nums[k+1])) && (inc == 1 && dec == 0 ==> \forall integer k; 0 <= k < i ==> nums[k] <= nums[k+1]) && (inc == 1 && dec == 0 ==> \exists integer k; 0 <= k < i && nums[k] < nums[k+1]) && (inc == 1 && dec == 0 ==> (\forall integer k; 0 <= k < i ==> nums[k] <= nums[k+1])) && (inc == 1 && dec == 0 ==> (\exists integer k; 0 <= k < i && nums[k] < nums[k+1])) && (inc == 0 || inc == 1) && (inc == 0 || dec == 0 || (\forall integer k; 0 <= k < i ==> nums[k] == nums[k+1])) && (inc == 0 ==> dec == 1 || dec == 0) && (inc == 0 ==> dec == 0 || dec == 1) && (inc == 0 ==> \exists integer k; 0 <= k < i && nums[k] > nums[k+1]) && (inc == 0 ==> (\exists integer k; 0 <= k < i && nums[k] > nums[k+1])) && (inc == 0 ==> (\exists integer k; 0 <= k < i && nums[k] != nums[k+1])) && (inc == 0 && dec == 1 ==> \forall integer k; 0 <= k < i ==> nums[k] >= nums[k+1]) && (inc == 0 && dec == 1 ==> \exists integer k; 0 <= k < i && nums[k] > nums[k+1]) && (inc == 0 && dec == 1 ==> (\forall integer k; 0 <= k < i ==> nums[k] >= nums[k+1])) && (inc == 0 && dec == 1 ==> (\exists integer k; 0 <= k < i && nums[k] > nums[k+1])) && (inc == 0 && dec == 0 ==> \exists integer k; 0 <= k < i && nums[k] != nums[k+1]) && (inc == 0 && dec == 0 ==> (\exists integer k; 0 <= k < i && nums[k] > nums[k+1]) && (\exists integer k; 0 <= k < i && nums[k] < nums[k+1])) && (inc == 0 && dec == 0 ==> (\exists integer k; 0 <= k < i && nums[k] < nums[k+1]) && (\exists integer k; 0 <= k < i && nums[k] > nums[k+1])) && (inc == 0 && dec == 0 ==> (\exists integer k; 0 <= k < i && nums[k] != nums[k+1])) && (i == 0 ==> inc == 1 && dec == 1) && (dec == 1 || dec == 0) && (dec == 1 ==> inc == 1 || inc == 0) && (dec == 1 ==> \forall integer k; 0 <= k < i ==> nums[k] >= nums[k+1]) && (dec == 1 ==> \forall integer k; 0 <= k < i ==> nums[k] >= nums[k + 1]) && (dec == 1 ==> (\forall integer k; 0 <= k < i ==> nums[k] >= nums[k+1])) && (dec == 1 && inc == 0 ==> (\forall integer k; 0 <= k < i ==> nums[k] >= nums[k+1])) && (dec == 0 || dec == 1) && (dec == 0 ==> inc == 1 || inc == 0) && (dec == 0 ==> inc == 0 || inc == 1) && (dec == 0 ==> \exists integer k; 0 <= k < i && nums[k] < nums[k+1]) && (dec == 0 ==> (\exists integer k; 0 <= k < i && nums[k] < nums[k+1])) && (dec == 0 ==> (\exists integer k; 0 <= k < i && nums[k] != nums[k+1])) && (\forall integer k; 0 <= k < i ==> (nums[k] > nums[k+1] ==> inc == 0)) && (\forall integer k; 0 <= k < i ==> (nums[k] < nums[k+1] ==> dec == 0)) && (0 <= i) && (0 <= i || n <= 1) && ((inc == 1) ==> (\forall integer k; 0 <= k < i ==> nums[k] <= nums[k+1])) && ((inc == 1) <==> (\forall integer k; 0 <= k < i ==> nums[k] <= nums[k+1])) && ((inc == 1 && dec == 0) ==> (\forall integer k; 0 <= k < i ==> nums[k] <= nums[k+1])) && ((inc == 0) ==> (\exists integer k; 0 <= k < i && nums[k] > nums[k+1])) && ((inc == 0 || dec == 0) ==> (\exists integer k; 0 <= k < i && nums[k] != nums[k+1])) && ((inc == 0 && dec == 1) ==> (\forall integer k; 0 <= k < i ==> nums[k] >= nums[k+1])) && ((dec == 1) ==> (\forall integer k; 0 <= k < i ==> nums[k] >= nums[k+1])) && ((dec == 1) <==> (\forall integer k; 0 <= k < i ==> nums[k] >= nums[k+1])) && ((dec == 0) ==> (\exists integer k; 0 <= k < i && nums[k] < nums[k+1])) && ((\forall integer k; 0 <= k < i ==> nums[k] >= nums[k+1]) ==> dec == 1) && ((\forall integer k; 0 <= k < i ==> nums[k] > nums[k+1] ==> inc == 0)) && ((\forall integer k; 0 <= k < i ==> nums[k] <= nums[k+1]) ==> inc == 1) && ((\forall integer k; 0 <= k < i ==> nums[k] < nums[k+1] ==> dec == 0)) && ((\forall integer k; 0 <= k < i && nums[k] > nums[k+1] ==> inc == 0)) && ((\forall integer k; 0 <= k < i && nums[k] < nums[k+1] ==> dec == 0)) && ((\exists integer k; 0 <= k < i && nums[k] > nums[k+1]) ==> inc == 0) && ((\exists integer k; 0 <= k < i && nums[k] < nums[k+1]) ==> dec == 0);
    assigns \nothing;
*/
void check_B_implies_A(int dec, int i, int inc, int k, int n, int *nums, int nums_len) {
    /*@ assert (0 <= i); */
    /*@ assert ((n < 0) || (i <= n)); */
    /*@ assert (0 <= inc <= 1); */
    /*@ assert (0 <= dec <= 1); */
    /*@ assert (n == \at(nums_len,Pre)); */
    /*@ assert (nums_len == \at(nums_len,Pre)); */
    /*@ assert (nums == \at(nums,Pre)); */
    /*@ assert (\forall integer k; 0 <= k < n ==> nums[k] == \at(nums[k],Pre)); */
    /*@ assert (inc == 1 ==> \forall integer k; 0 <= k < i ==> nums[k] <= nums[k+1]); */
    /*@ assert (dec == 1 ==> \forall integer k; 0 <= k < i ==> nums[k] >= nums[k+1]); */
    /*@ assert ((i < \at(nums_len,Pre) - 1) ==> (((n == \at(nums_len,Pre))&&(dec == 1)&&(inc == 1)&&(nums_len == \at(nums_len,Pre))&&(nums == \at(nums,Pre))) || (0 <= inc <= 1))); */
    /*@ assert ((i < \at(nums_len,Pre) - 1) ==> (((n == \at(nums_len,Pre))&&(dec == 1)&&(inc == 1)&&(nums_len == \at(nums_len,Pre))&&(nums == \at(nums,Pre))) || (0 <= dec <= 1))); */
    /*@ assert (n == \at(nums_len,Pre)); */
    /*@ assert (nums_len == \at(nums_len,Pre)); */
    /*@ assert (nums == \at(nums,Pre)); */
    /*@ assert (\forall integer k; 0 <= k < n ==> nums[k] == \at(nums[k],Pre)); */
}
