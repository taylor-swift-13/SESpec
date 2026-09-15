

/*@
  requires nums_len >= 0;
  requires \valid(&nums[0] + (0..nums_len-1));
  requires \forall integer i; 0 <= i < nums_len ==> 0 <= nums[i] <= 100;
  assigns \nothing;
  ensures nums_len == \at(nums_len,Pre);
  ensures nums == \at(nums,Pre);
  ensures \forall integer k; 0 <= k < \at(nums_len,Pre) ==> nums[k] == \at(nums[k],Pre);
  ensures \result == 1 ==> ((\forall integer i; 0 <= i < nums_len - 1 ==> nums[i] <= nums[i+1]) || (\forall integer i; 0 <= i < nums_len - 1 ==> nums[i] >= nums[i+1]));
*/
int foo120(int * nums, int nums_len) {

        int inc = 1, dec = 1;
        int n = nums_len;
        
        /* >>> LOOP INVARIANT TO FILL <<< */
        
        /*@
          loop invariant 0 <= inc <= 1;
          loop invariant 0 <= dec <= 1;

          loop invariant inc == 1 ==> (\forall integer k; 0 <= k < i ==> nums[k] <= nums[k+1]);
          loop invariant (\exists integer k; 0 <= k < i && nums[k] > nums[k+1]) ==> inc == 0;

          loop invariant dec == 1 ==> (\forall integer k; 0 <= k < i ==> nums[k] >= nums[k+1]);
          loop invariant (\exists integer k; 0 <= k < i && nums[k] < nums[k+1]) ==> dec == 0;
          loop invariant (i == n - 1) ==> (dec == 1 ==> (\forall integer k; 0 <= k < n - 1 ==> nums[k] >= nums[k+1]));
          loop invariant (i < \at(nums_len,Pre) - 1) ==> (((n == \at(nums_len,Pre))&&(dec == 1)&&(inc == 1)&&(nums_len == \at(nums_len,Pre))&&(nums == \at(nums,Pre))) || (inc == 1 ==> (\forall integer k; 0 <= k < i ==> nums[k] <= nums[k+1])));
          loop invariant (i < \at(nums_len,Pre) - 1) ==> (((n == \at(nums_len,Pre))&&(dec == 1)&&(inc == 1)&&(nums_len == \at(nums_len,Pre))&&(nums == \at(nums,Pre))) || (dec == 1 ==> (\forall integer k; 0 <= k < i ==> nums[k] >= nums[k+1])));
          loop invariant n == \at(nums_len,Pre);
          loop invariant nums_len == \at(nums_len,Pre);
          loop invariant nums == \at(nums,Pre);
          loop invariant \forall integer k; 0 <= k < \at(nums_len,Pre) ==> nums[k] == \at(nums[k],Pre);
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
