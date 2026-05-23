
int foo101(int * nums, int nums_len) {

        int max = nums[0];
        int min = nums[0];
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= i;
          loop invariant \forall integer k; 0 <= k < i ==> nums[k] <= max;
          loop invariant \forall integer k; 0 <= k < i ==> nums[k] >= min;
          loop invariant \forall integer k; 0 <= k < nums_len ==> nums[k] == \at(nums[k],Pre);
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
