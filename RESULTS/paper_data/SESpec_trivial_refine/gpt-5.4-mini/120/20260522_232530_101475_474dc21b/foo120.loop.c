
        /*@
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
