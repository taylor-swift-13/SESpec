
        /*@
        requires nums_len > 0;
        requires \valid_read(nums + (0 .. nums_len-1));
        */
        
int foo242(int * nums, int nums_len) {

        int max = nums[0];
        int min = nums[0];
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= i <= nums_len;
          loop invariant max >= min;
          loop invariant \forall integer j; 1 <= j < i ==> max >= nums[j];
          loop invariant \forall integer j; 1 <= j < i ==> min <= nums[j];
          loop assigns i, max, min;
          loop variant nums_len - i;
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
