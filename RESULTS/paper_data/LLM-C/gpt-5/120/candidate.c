int isMonotonic(int * nums, int nums_len);

/*@ 
  predicate NonDecreasing(int *a, integer n) =
    \forall integer k; 0 <= k && k + 1 < n ==> a[k] <= a[k + 1];

  predicate NonIncreasing(int *a, integer n) =
    \forall integer k; 0 <= k && k + 1 < n ==> a[k] >= a[k + 1];
*/

/*@ 
  requires nums_len >= 0;
  requires nums_len <= 1 || \valid_read(nums + (0 .. nums_len-1));
  assigns \nothing;
  ensures \result == 0 || \result == 1;
  ensures (\result != 0) <==> (NonDecreasing(nums, nums_len) || NonIncreasing(nums, nums_len));
*/
int isMonotonic(int * nums, int nums_len) {

        int inc = 1, dec = 1;
        int n = nums_len;
        /*@ 
          loop invariant 0 <= n;
          loop invariant n <= 1 || \valid_read(nums + (0 .. n-1));
          loop invariant 0 <= i;
          loop invariant i <= n-1 || n <= 0;
          loop invariant inc == 1 <==> (\forall integer k; 0 <= k < i ==> nums[k] <= nums[k+1]);
          loop invariant dec == 1 <==> (\forall integer k; 0 <= k < i ==> nums[k] >= nums[k+1]);
          loop invariant inc == 0 ==> (\exists integer k; 0 <= k < i && nums[k] > nums[k+1]);
          loop invariant dec == 0 ==> (\exists integer k; 0 <= k < i && nums[k] < nums[k+1]);
          loop assigns inc, dec, i;
          loop variant (n - 1) - i;
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
