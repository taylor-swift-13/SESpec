
/*@ logic integer count_decr(int* a, integer lo, integer hi) =
      lo >= hi - 1 ? 0
                   : count_decr(a, lo, hi - 1) + (a[hi-2] > a[hi-1] ? 1 : 0);
*/

/*@ logic integer count_incr(int* a, integer lo, integer hi) =
      lo >= hi - 1 ? 0
                   : count_incr(a, lo, hi - 1) + (a[hi-2] < a[hi-1] ? 1 : 0);
*/

/*@ predicate prefix_nondecreasing(int* a, integer k) =
      k <= 1 ? \true : (\forall integer j; 0 <= j < k-1 ==> a[j] <= a[j+1]);
*/

/*@ predicate prefix_nonincreasing(int* a, integer k) =
      k <= 1 ? \true : (\forall integer j; 0 <= j < k-1 ==> a[j] >= a[j+1]);
*/

/*@
  predicate same_array_at{L}(int* a, integer len) =
    \forall integer j; 0 <= j < len ==> a[j] == \at(a[j], L);
*/

/*@
  requires \at(nums_len,Pre) > 0 && \at(nums_len,Pre) < 100;
  requires \valid_read(nums + (0 .. nums_len-1));
  requires nums_len == \at(nums_len,Pre);
  assigns \nothing;
*/
int foo120(int * nums, int nums_len) {

        int inc = 1, dec = 1;
        int n = nums_len;
        
            
        /*@
          loop invariant 0 <= i <= n - 1;
          loop invariant n == \at(nums_len,Pre);
          loop invariant nums_len == \at(nums_len,Pre);
          loop invariant nums == \at(nums,Pre);
          loop invariant same_array_at{Pre}(nums, \at(nums_len,Pre));
          loop assigns i, inc, dec;
        */
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] > nums[i + 1]) {
                inc = 0;
            }
            if (nums[i] < nums[i + 1]) {
                dec = 0;
            }
        }
            
        return inc || dec;
}
