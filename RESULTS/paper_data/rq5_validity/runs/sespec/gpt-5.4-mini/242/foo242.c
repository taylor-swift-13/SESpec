
/*@
  requires \valid(&nums[0] + (0..nums_len-1));
  requires \forall integer i; 0 <= i < nums_len ==> 0 <= nums[i] <= 100;
  assigns \nothing;
*/
int foo242(int * nums, int nums_len) {

        int max = nums[0];
        int min = nums[0];
        
        /*@
          loop invariant 0 <= i;
          loop invariant max >= min;
          loop invariant \forall integer k; 0 <= k < i ==> nums[k] <= max;
          loop invariant \forall integer k; 0 <= k < i ==> nums[k] >= min;
          loop invariant \forall integer k; 0 <= k < i ==> min <= nums[k];
          loop invariant \forall integer k; 0 <= k < i ==> nums[k] <= max;
          loop invariant \forall integer k; 0 <= k < nums_len ==> nums[k] == \at(nums[k], Pre);
          loop invariant (i >= nums_len) ==> (max >= min);
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
