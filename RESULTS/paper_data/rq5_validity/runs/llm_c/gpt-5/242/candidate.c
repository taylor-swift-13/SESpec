int bigDiff(int * nums, int nums_len);

/*@ 
  predicate is_max{L}(int *a, integer len, integer m) =
    len > 0 &&
    (\forall integer i; 0 <= i < len ==> \at(a[i],L) <= m) &&
    (\exists integer i; 0 <= i < len && \at(a[i],L) == m);

  predicate is_min{L}(int *a, integer len, integer m) =
    len > 0 &&
    (\forall integer i; 0 <= i < len ==> \at(a[i],L) >= m) &&
    (\exists integer i; 0 <= i < len && \at(a[i],L) == m);
*/

/*@ 
  requires nums != \null;
  requires nums_len >= 1;
  requires \valid_read(nums + (0 .. nums_len-1));
  assigns \nothing;
  ensures \exists integer M, m;
            is_max{Pre}(nums, nums_len, M) &&
            is_min{Pre}(nums, nums_len, m) &&
            \result == M - m;
  ensures nums_len == 1 ==> \result == 0;
*/
int bigDiff(int * nums, int nums_len) {

        int max = nums[0];
        int min = nums[0];
        /*@
          loop invariant 1 <= i <= nums_len;
          loop invariant is_max{Pre}(nums, i, max);
          loop invariant is_min{Pre}(nums, i, min);
          loop invariant max >= min;
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
