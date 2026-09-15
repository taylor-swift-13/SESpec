
        /*@
        */

/*@
  requires nums_len >= 0;
  requires nums_len <= 0 || \valid_read(nums + (0 .. nums_len - 1));
  assigns \nothing;
  ensures nums_len <= 1 ==> \result == 1;
  ensures \result == 1 <==> ((\forall integer k; 0 <= k < nums_len - 1 ==> nums[k] <= nums[k + 1]) || (\forall integer k; 0 <= k < nums_len - 1 ==> nums[k] >= nums[k + 1]));
  ensures \result == 0 <==> (\exists integer k; 0 <= k < nums_len - 1 && nums[k] > nums[k + 1] && (\exists integer j; 0 <= j < nums_len - 1 && nums[j] < nums[j + 1]));
  ensures \result == 0 || \result == 1;
*/
int foo120(int * nums, int nums_len) {

        int inc = 1, dec = 1;
        int n = nums_len;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= i;
          loop invariant inc == 0 || inc == 1;
          loop invariant dec == 0 || dec == 1;
          loop invariant inc == 1 ==> (\forall integer k; 0 <= k < i ==> nums[k] <= nums[k + 1]);
          loop invariant dec == 1 ==> (\forall integer k; 0 <= k < i ==> nums[k] >= nums[k + 1]);
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
