
/*@
PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
*/
        
/*@
  requires nums_len > 0;
  requires \valid_read(nums + (0 .. nums_len - 1));
  assigns \nothing;
  ensures 0 <= \result < nums_len ==> nums[\result] == max_array(nums, nums_len);
  ensures \result == -1 <==> (\exists integer j; 0 <= j < nums_len && 2 * nums[j] > max_array(nums, nums_len));
  ensures \result != -1 ==> (\forall integer j; 0 <= j < nums_len ==> nums[\result] >= nums[j]);
  ensures \result != -1 ==> (\forall integer j; 0 <= j < nums_len && j != \result ==> 2 * nums[j] <= nums[\result]);
  ensures \result == -1 ==> (\exists integer j; 0 <= j < nums_len && 2 * nums[j] > nums[\result + 1]);
*/
int foo104(int * nums, int nums_len) {

        int biggest_index = 0;

        /*@
          loop invariant 0 <= i;
          loop invariant 0 <= biggest_index <= i;
          loop invariant \forall integer j; 0 <= j < i ==> nums[biggest_index] >= nums[j];
          loop assigns i, biggest_index;
        */
        for (int i = 0; i < nums_len; i++) {
            if (nums[i] > nums[biggest_index])
                biggest_index = i;
        }

        /*@
          loop invariant 0 <= i <= nums_len;
          loop invariant 0 <= biggest_index < nums_len;
          loop invariant \forall integer j; 0 <= j < i ==> (j == biggest_index || 2 * nums[j] <= nums[biggest_index]);
          loop assigns i;
        */
        for (int i = 0; i < nums_len; i++) {
            if (i != biggest_index && 2 * nums[i] > nums[biggest_index])
                return -1;
        }

        return biggest_index;
}
