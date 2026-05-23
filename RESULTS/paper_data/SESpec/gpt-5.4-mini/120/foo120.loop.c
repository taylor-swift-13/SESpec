
int foo120(int * nums, int nums_len) {

        int inc = 1, dec = 1;
        int n = nums_len;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= i;
          loop invariant (n < 0) || (i <= n);
          loop invariant 0 <= inc <= 1;
          loop invariant 0 <= dec <= 1;
          loop invariant n == \at(nums_len,Pre);
          loop invariant nums_len == \at(nums_len,Pre);
          loop invariant nums == \at(nums,Pre);
          loop invariant \forall integer k; 0 <= k < n ==> nums[k] == \at(nums[k],Pre);
          loop invariant inc == 1 ==> \forall integer k; 0 <= k < i ==> nums[k] <= nums[k+1];
          loop invariant dec == 1 ==> \forall integer k; 0 <= k < i ==> nums[k] >= nums[k+1];
          loop invariant (i < \at(nums_len,Pre) - 1) ==> (((n == \at(nums_len,Pre))&&(dec == 1)&&(inc == 1)&&(nums_len == \at(nums_len,Pre))&&(nums == \at(nums,Pre))) || (0 <= inc <= 1));
          loop invariant (i < \at(nums_len,Pre) - 1) ==> (((n == \at(nums_len,Pre))&&(dec == 1)&&(inc == 1)&&(nums_len == \at(nums_len,Pre))&&(nums == \at(nums,Pre))) || (0 <= dec <= 1));
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
