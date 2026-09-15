
/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  assigns \nothing;
  ensures (nums_len > 0 && \result != -1) ==> (\forall integer k; 0 <= k && k < nums_len ==> nums[\result] >= nums[k]);
  ensures (nums_len > 0 && \result != -1) ==> (\forall integer k; 0 <= k && k < nums_len ==> (k != \result ==> 2 * nums[k] <= nums[\result]));
*/
int foo104(int * nums, int nums_len) {

        int biggest_index = 0;

        /*@ 
          loop invariant nums_len == \at(nums_len,Pre);
          loop invariant nums == \at(nums,Pre);
          loop invariant \forall integer k; 0 <= k && k < nums_len ==> nums[k] == \at(nums[k], Pre);
          loop invariant (i > 0) ==> (\forall integer k; 0 <= k && k < i ==> nums[biggest_index] >= nums[k]);
          loop invariant (i == nums_len && nums_len > 0) ==> (\forall integer k; 0 <= k && k < nums_len ==> nums[biggest_index] >= nums[k]);

          loop invariant (i < \at(nums_len,Pre)) ==> (nums_len >= 0);
          loop invariant nums_len == \at(nums_len,Pre);
          loop invariant nums == \at(nums,Pre);
          loop invariant \forall integer k; 0 <= k && k < nums_len ==> nums[k] == \at(nums[k], Pre) ;
          loop assigns i, biggest_index;
        */
        for (int i = 0; i < nums_len; i++) {
            if (nums[i] > nums[biggest_index])
                biggest_index = i;
        }

        /*@ 
          loop invariant nums_len == \at(nums_len,Pre);
          loop invariant nums == \at(nums,Pre);
          loop invariant \forall integer k; 0 <= k && k < nums_len ==> nums[k] == \at(nums[k], Pre);
          loop invariant \forall integer k; 0 <= k && k < i ==> (k != biggest_index ==> 2 * nums[k] <= nums[biggest_index]);
          loop invariant !(i < nums_len) ==> (\forall integer k; 0 <= k && k < nums_len ==> (k != biggest_index ==> 2 * nums[k] <= nums[biggest_index]));
          loop assigns i;
        */
        for (int i = 0; i < nums_len; i++) {
            if (i != biggest_index && 2 * nums[i] > nums[biggest_index])
                return -1;
        }

        return biggest_index;
}
