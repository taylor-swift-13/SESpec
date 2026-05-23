
/*@
  logic integer max_prefix(int *a, integer n) =
    n <= 0 ? 0 : (n == 1 ? a[0] : (a[n-1] > max_prefix(a, n-1) ? a[n-1] : max_prefix(a, n-1)));
*/

/*@
  requires \valid(&nums[0] + (0..nums_len-1));
  requires \forall integer i; 0 <= i < nums_len ==> 0 <= nums[i] <= 100;
  requires nums_len > 0;
  requires nums_len < 100;
  assigns \nothing;
  ensures
    (\result == -1 ==>
      (\exists integer i;
         0 <= i < nums_len &&
         i !=
           (\let bi = (\numof integer j; 0 <= j < nums_len && nums[j] == max_prefix(nums, nums_len)) >= 1 ?
             (\let k = (\sum integer t; 0 <= t < nums_len && nums[t] == max_prefix(nums, nums_len) ? t : 0); k) : 0; bi) &&
         2 * nums[i] > nums[
           (\let bi2 = (\numof integer j2; 0 <= j2 < nums_len && nums[j2] == max_prefix(nums, nums_len)) >= 1 ?
             (\let k2 = (\sum integer t2; 0 <= t2 < nums_len && nums[t2] == max_prefix(nums, nums_len) ? t2 : 0); k2) : 0; bi2)]))
    &&
    (\result != -1 ==>
      0 <= \result < nums_len &&
      nums[\result] == max_prefix(nums, nums_len) &&
      (\forall integer i; 0 <= i < nums_len ==> (i == \result || 2 * nums[i] <= nums[\result])));
  ensures \result == -1 || (0 <= \result < nums_len && nums[\result] == max_prefix(nums, nums_len));
*/
int foo104(int * nums, int nums_len) {

        int biggest_index = 0;

        /*@
          loop invariant 0 <= biggest_index < (i == 0 ? 1 : i) || i == 0;
          loop invariant i == 0 ==> biggest_index == 0;
          loop invariant i > 0 ==> 0 <= biggest_index < i;
          loop invariant i > 0 ==> nums[biggest_index] == max_prefix(nums, i);
          loop assigns i, biggest_index;
        */
        for (int i = 0; i < nums_len; i++) {
            if (nums[i] > nums[biggest_index])
                biggest_index = i;
        }

        /*@
          loop assigns i;
        */
        for (int i = 0; i < nums_len; i++) {
            if (i != biggest_index && 2 * nums[i] > nums[biggest_index])
                return -1;
        }

        return biggest_index;
}
