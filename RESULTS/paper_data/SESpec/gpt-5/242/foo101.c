
/*@ logic integer max_in_range{L}(int *a, integer lo, integer hi) =
      lo + 1 == hi ? a[lo] :
      (a[lo] > max_in_range{L}(a, lo + 1, hi) ? a[lo] : max_in_range{L}(a, lo + 1, hi));
*/

/*@ logic integer min_in_range{L}(int *a, integer lo, integer hi) =
      lo + 1 == hi ? a[lo] :
      (a[lo] < min_in_range{L}(a, lo + 1, hi) ? a[lo] : min_in_range{L}(a, lo + 1, hi));
*/

/*@
  requires nums_len > 0;
  requires nums_len < 100;
  requires \valid(&nums[0] + (0..nums_len-1));
  requires \forall integer i; 0 <= i < nums_len ==> 0 <= nums[i] <= 100;
  assigns \nothing;
*/
int foo101(int * nums, int nums_len) {

        int max = nums[0];
        int min = nums[0];
        
        /*@
          loop invariant 1 <= i <= nums_len;
          loop invariant \forall integer k; 0 <= k < i ==> nums[k] <= max;
          loop invariant \forall integer k; 0 <= k < i ==> nums[k] >= min;
          loop invariant \forall integer k; 0 <= k < nums_len ==> nums[k] == \at(nums[k],Pre);
          loop invariant nums_len == \at(nums_len,Pre);
          loop invariant nums == \at(nums,Pre);
          loop assigns i, max, min;
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
