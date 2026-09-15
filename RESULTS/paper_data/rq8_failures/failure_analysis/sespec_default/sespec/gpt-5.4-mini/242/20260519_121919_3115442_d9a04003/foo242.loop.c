
/*@
  logic integer array_max(int* nums, integer lo, integer hi) =
    lo >= hi ? nums[0] : (hi - 1 == lo ? nums[lo] :
      (nums[hi - 1] > array_max(nums, lo, hi - 1) ? nums[hi - 1] : array_max(nums, lo, hi - 1)));

  logic integer array_min(int* nums, integer lo, integer hi) =
    lo >= hi ? nums[0] : (hi - 1 == lo ? nums[lo] :
      (nums[hi - 1] < array_min(nums, lo, hi - 1) ? nums[hi - 1] : array_min(nums, lo, hi - 1)));
*/

int foo242(int * nums, int nums_len) {

        int max = nums[0];
        int min = nums[0];
        
            
        /*@
          loop invariant \forall integer k; 0 <= k < i ==> min <= nums[k] <= max;
          loop invariant nums_len == \at(nums_len,Pre);
          loop invariant nums == \at(nums,Pre);
          loop assigns i, max, min;
        */
        for (int i = 1; i < nums_len; i++) {
            if (nums[i] > max) {
                max = nums[i];
            }
            if (nums[i] < min) {
                min = nums[i];
            }
        }
            
        return max - min;
}
