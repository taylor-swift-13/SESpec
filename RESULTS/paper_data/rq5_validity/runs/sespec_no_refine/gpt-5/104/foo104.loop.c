
/*@
  logic integer max_prefix(int *a, integer n) =
    n <= 0 ? 0 : (n == 1 ? a[0] : (a[n-1] > max_prefix(a, n-1) ? a[n-1] : max_prefix(a, n-1)));
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
