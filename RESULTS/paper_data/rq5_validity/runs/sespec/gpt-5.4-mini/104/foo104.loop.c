
/*@
  requires nums_len >= 0;
  requires \valid_read(nums + (0 .. nums_len - 1));
*/

int foo104(int * nums, int nums_len) {

        int biggest_index = 0;

        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= i <= nums_len;
          loop invariant 0 <= biggest_index <= i;
          loop invariant i == 0 ==> biggest_index == 0;
          loop invariant i > 0 ==> 0 <= biggest_index < i;
          loop invariant i > 0 ==> \forall integer k; 0 <= k < i ==> nums[k] <= nums[biggest_index];
          loop invariant i > 0 ==> \exists integer k; 0 <= k < i && nums[k] == nums[biggest_index];
          loop invariant nums_len == \at(nums_len,Pre);
          loop invariant nums == \at(nums,Pre);
          loop invariant \forall integer k; 0 <= k < nums_len ==> nums[k] == \at(nums[k], Pre);
          loop assigns i, biggest_index;
            */
            for (int i = 0; i < nums_len; i++) {
            if (nums[i] > nums[biggest_index])
                biggest_index = i;
        }
            

        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= i <= nums_len;
          loop invariant 0 <= biggest_index <= nums_len;
          loop invariant \forall integer k; 0 <= k < i ==> (k == biggest_index || 2 * nums[k] <= nums[biggest_index]);
          loop invariant \forall integer k; 0 <= k < nums_len ==> nums[k] == \at(nums[k], Pre);
          loop assigns i;
            */
            for (int i = 0; i < nums_len; i++) {
            if (i != biggest_index && 2 * nums[i] > nums[biggest_index])
                return -1;
        }
            

        return biggest_index;
}
