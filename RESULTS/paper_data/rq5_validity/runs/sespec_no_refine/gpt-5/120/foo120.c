
        /*@
  requires nums_len >= 0;
  requires \valid(nums + (0 .. nums_len-1));
  assigns \nothing;
  ensures \result == 0 || \result == 1;
*/
int foo120(int * nums, int nums_len) {

        int inc = 1, dec = 1;
        int n = nums_len;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant inc == 1 ==> (\forall integer k; 0 <= k < i ==> nums[k] <= nums[k+1]);
          loop invariant dec == 1 ==> (\forall integer k; 0 <= k < i ==> nums[k] >= nums[k+1]);
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
