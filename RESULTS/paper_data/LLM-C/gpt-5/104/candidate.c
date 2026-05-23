int dominantIndex(int * nums, int nums_len);

/*@
  requires nums_len > 0;
  requires \valid_read(nums + (0 .. nums_len-1));
  assigns \nothing;

  ensures (\result == -1) ||
          (0 <= \result < nums_len &&
           (\forall integer i; 0 <= i < nums_len ==> nums[\result] >= nums[i]) &&
           (\forall integer i; 0 <= i < nums_len && i != \result ==> 2*nums[i] <= nums[\result]));

  ensures (\result == -1) ==>
           (\forall integer j;
              0 <= j < nums_len &&
              (\forall integer k; 0 <= k < nums_len ==> nums[j] >= nums[k])
              ==> (\exists integer i; 0 <= i < nums_len && i != j && 2*nums[i] > nums[j]));
*/
int dominantIndex(int * nums, int nums_len) {

        int biggest_index = 0;

        /*@
          loop invariant 0 <= i <= nums_len;
          loop invariant 0 <= biggest_index < nums_len;
          loop invariant \forall integer k; 0 <= k < i ==> nums[biggest_index] >= nums[k];
          loop assigns i, biggest_index;
          loop variant nums_len - i;
        */
        for (int i = 0; i < nums_len; i++) {
            if (nums[i] > nums[biggest_index])
                biggest_index = i;
        }

        /*@ assert \forall integer k; 0 <= k < nums_len ==> nums[biggest_index] >= nums[k]; */

        /*@
          loop invariant 0 <= i <= nums_len;
          loop invariant 0 <= biggest_index < nums_len;
          loop invariant \forall integer k; 0 <= k < nums_len ==> nums[biggest_index] >= nums[k];
          loop invariant \forall integer k; 0 <= k < i && k != biggest_index ==> 2*nums[k] <= nums[biggest_index];
          loop assigns i;
          loop variant nums_len - i;
        */
        for (int i = 0; i < nums_len; i++) {
            if (i != biggest_index && 2 * nums[i] > nums[biggest_index])
                return -1;
        }

        return biggest_index;
}
