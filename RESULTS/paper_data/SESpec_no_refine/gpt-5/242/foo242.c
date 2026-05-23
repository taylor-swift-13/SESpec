
/*@
*/

/*@
  requires \valid(&nums[0] + (0..nums_len-1));
  requires \forall integer i; 0 <= i < nums_len ==> 0 <= nums[i] <= 100;
  requires nums_len > 0;
  requires nums_len < 100;
  assigns \nothing;
  ensures \result == array_max{Pre}(nums, nums_len) - array_min{Pre}(nums, nums_len);
*/
int foo242(int * nums, int nums_len) {

        int max = nums[0];
        int min = nums[0];
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= i <= nums_len;
          loop invariant \forall integer k; 0 <= k < i ==> nums[k] <= max;
          loop invariant \forall integer k; 0 <= k < i ==> nums[k] >= min;
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
