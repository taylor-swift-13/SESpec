
/*@
  logic integer prefix_inc(int* nums, integer i) =
    i <= 0 ? 1 :
    (prefix_inc(nums, i - 1) && nums[i - 1] <= nums[i]) ? 1 : 0;

  logic integer prefix_dec(int* nums, integer i) =
    i <= 0 ? 1 :
    (prefix_dec(nums, i - 1) && nums[i - 1] >= nums[i]) ? 1 : 0;
*/

/*@
  requires \valid(&nums[0] + (0..nums_len-1));
  requires \forall integer i; 0 <= i < nums_len ==> 0 <= nums[i] <= 100;
  requires nums_len > 0;
  requires nums_len < 100;
  assigns \nothing;
*/
int foo43(int * nums, int nums_len) {

        int inc = 1, dec = 1;
        int n = nums_len;
        
            
        /*@
          loop invariant n == \at(nums_len,Pre);
          loop invariant nums_len == \at(nums_len,Pre);
          loop invariant nums == \at(nums,Pre);
          loop invariant \forall integer k; 0 <= k < nums_len ==> nums[k] == \at(nums[k], Pre);
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
