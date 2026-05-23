
/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@ 
  requires nums_len >= 0;
  requires \valid_read(nums + (0..nums_len-1));
  ensures 0 <= \result < (nums_len == 0 ? 1 : nums_len) || (nums_len == 0 && \result == 0);
*/

int foo104(int * nums, int nums_len) {

        int biggest_index = 0;

        /*@ 
          loop invariant 0 <= i <= nums_len;
          loop invariant nums_len == \at(nums_len,Pre);
          loop invariant nums == \at(nums,Pre);
          loop invariant \forall integer k; 0 <= k < nums_len ==> nums[k] == \at(nums[k], Pre);
          loop invariant (i == 0) ==> biggest_index == 0;
          loop invariant (i > 0) ==> 0 <= biggest_index < i;
          loop invariant (i > 0) ==> \forall integer k; 0 <= k < i ==> nums[biggest_index] >= nums[k];
          loop invariant (i > 0) ==> \exists integer k; 0 <= k < i && nums[k] == nums[biggest_index];
          loop invariant (i == nums_len && nums_len > 0) ==> \forall integer k; 0 <= k < nums_len ==> nums[biggest_index] >= nums[k];

          loop invariant (i < \at(nums_len,Pre)) ==> (nums_len >= 0);
          loop invariant (i < \at(nums_len,Pre)) ==> (((biggest_index == 0)&&(nums_len == \at(nums_len,Pre))&&(nums == \at(nums,Pre))) || (0 <= biggest_index < i));
          loop invariant nums_len == \at(nums_len,Pre);
          loop invariant nums == \at(nums,Pre);
          loop invariant \forall integer k; 0 <= k < nums_len ==> nums[k] == \at(nums[k], Pre) ;
          loop assigns i, biggest_index;
        */
        for (int i = 0; i < nums_len; i++) {
            if (nums[i] > nums[biggest_index])
                biggest_index = i;
        }

        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= i <= nums_len;
          loop invariant nums_len == \at(nums_len,Pre);
          loop invariant nums == \at(nums,Pre);
          loop invariant \forall integer k; 0 <= k < nums_len ==> nums[k] == \at(nums[k], Pre);
          loop invariant \forall integer k; 0 <= k < i ==> (k != biggest_index ==> 2 * nums[k] <= nums[biggest_index]);
          loop invariant (!(i < nums_len)) ==> (\forall integer k; 0 <= k < nums_len ==> (k != biggest_index ==> 2 * nums[k] <= nums[biggest_index]));
          loop assigns i;
            */
            for (int i = 0; i < nums_len; i++) {
            if (i != biggest_index && 2 * nums[i] > nums[biggest_index])
                return -1;
        }
            

        return biggest_index;
}
