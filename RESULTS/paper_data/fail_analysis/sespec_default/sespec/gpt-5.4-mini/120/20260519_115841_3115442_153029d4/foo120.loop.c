
/*@ 
  predicate nonincreasing_prefix(int *nums, integer n, integer i) =
    i <= 0 ? \true :
    (nonincreasing_prefix(nums, n, i - 1) && nums[i - 1] >= nums[i]);
*/

/*@ 
  predicate nondecreasing_prefix(int *nums, integer n, integer i) =
    i <= 0 ? \true :
    (nondecreasing_prefix(nums, n, i - 1) && nums[i - 1] <= nums[i]);
*/

/*@ 
  predicate all_equal_prefix(int *nums, integer n, integer i) =
    i <= 0 ? \true :
    (all_equal_prefix(nums, n, i - 1) && nums[i - 1] == nums[i]);
*/

int foo120(int * nums, int nums_len) {

        int inc = 1, dec = 1;
        int n = nums_len;
        
            
        /*@
          loop invariant (i < \at(nums_len,Pre) - 1) ==> ((inc == 1 && dec == 1) || (inc == 0 || dec == 0));
          loop invariant n == \at(nums_len,Pre);
          loop invariant nums_len == \at(nums_len,Pre);
          loop invariant nums == \at(nums,Pre);
          loop invariant \forall integer k; 0 <= k < n ==> nums[k] == \at(nums[k],Pre);
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
