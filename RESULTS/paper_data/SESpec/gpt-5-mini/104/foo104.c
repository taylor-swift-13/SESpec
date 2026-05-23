
/* No extra predicates required */

/*@
  requires nums_len > 0;
  requires \valid_read(nums + (0 .. nums_len-1));
  assigns \nothing;
  ensures (\exists integer j; 0 <= j < nums_len && ( ( \forall integer k; 0 <= k < nums_len ==> nums[j] >= nums[k]) && (\exists integer t; 0 <= t < nums_len && t != j && 2*nums[t] > nums[j]) )) ==> \result == -1;
  ensures (nums_len > 0 && \result != -1) ==> (0 <= \result < nums_len && (\forall integer k; 0 <= k < nums_len ==> nums[\result] >= nums[k]) && (\forall integer k; 0 <= k < nums_len ==> (k == \result ? \true : 2 * nums[k] <= nums[\result])));
  ensures \result == -1 || (nums_len > 0 && 0 <= \result < nums_len);
*/
int foo104(int * nums, int nums_len) {

    int biggest_index = 0;

    /* First loop: find index of a maximum element */
    /*@
      loop invariant 0 <= i <= nums_len;
      loop invariant nums_len == \at(nums_len,Pre);
      loop invariant nums == \at(nums,Pre);
      loop invariant \forall integer k; 0 <= k < nums_len ==> nums[k] == \at(nums[k],Pre);
      loop invariant 0 <= biggest_index < nums_len;
      loop invariant \forall integer k; 0 <= k < i ==> nums[biggest_index] >= nums[k];
      loop assigns i, biggest_index;
    */
    for (int i = 0; i < nums_len; i++) {
        if (nums[i] > nums[biggest_index])
            biggest_index = i;
    }

    /* Second loop: verify that largest element is at least twice every other */
    /*@
      loop invariant 0 <= i <= nums_len;
      loop invariant nums_len == \at(nums_len,Pre);
      loop invariant nums == \at(nums,Pre);
      loop invariant \forall integer k; 0 <= k < nums_len ==> nums[k] == \at(nums[k],Pre);
      loop invariant 0 <= biggest_index < nums_len;
      loop invariant \forall integer j; 0 <= j < i ==> (j == biggest_index ? \true : 2 * nums[j] <= nums[biggest_index]);
      loop invariant (!(i < nums_len)) ==> (\forall integer j; 0 <= j < nums_len ==> (j == biggest_index ? \true : 2 * nums[j] <= nums[biggest_index]));
      loop assigns i;
    */
    for (int i = 0; i < nums_len; i++) {
        if (i != biggest_index && 2 * nums[i] > nums[biggest_index])
            return -1;
    }

    return biggest_index;
}
