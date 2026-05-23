
/*@
  logic integer max_value(int* nums, integer lo, integer hi) =
    lo >= hi ? nums[0]
             : (nums[hi - 1] > max_value(nums, lo, hi - 1) ? nums[hi - 1] : max_value(nums, lo, hi - 1));

  logic integer min_value(int* nums, integer lo, integer hi) =
    lo >= hi ? nums[0]
             : (nums[hi - 1] < min_value(nums, lo, hi - 1) ? nums[hi - 1] : min_value(nums, lo, hi - 1));
*/

/*@
        PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
        */

/*@
  requires \valid(&nums[0] + (0..nums_len-1));
  requires \forall integer i; 0 <= i < nums_len ==> 0 <= nums[i] <= 100;
  requires nums_len > 0;
  requires nums_len < 100;
  assigns \nothing;
  ensures \result == max_value(nums, 0, nums_len) - min_value(nums, 0, nums_len);
*/
int foo101(int * nums, int nums_len) {

        int max = nums[0];
        int min = nums[0];
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant nums_len == \at(nums_len,Pre);
          loop invariant nums == \at(nums,Pre);
          loop invariant nums[0] == \at(nums[0],Pre);
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
