/*@ 
  logic integer count_nonzero{L}(int *a, integer n) reads a[0..n-1] =
    n <= 0 ? 0 : count_nonzero{L}(a, n-1) + (a[n-1] != 0 ? 1 : 0);

  logic integer first_nonzero_index_from{L}(int *a, integer n, integer i) reads a[0..n-1] =
    i >= n ? n : (a[i] != 0 ? i : first_nonzero_index_from{L}(a, n, i+1));

  logic integer nth_nonzero_index{L}(int *a, integer n, integer k) reads a[0..n-1] =
    k == 0 ? first_nonzero_index_from{L}(a, n, 0)
           : first_nonzero_index_from{L}(a, n, nth_nonzero_index{L}(a, n, k-1) + 1);
*/

/*@ requires nums_len >= 0;
    requires \valid(nums + (0 .. nums_len-1));
    assigns \nothing;
*/
void moveZeroes(int * nums, int nums_len);
/*@ requires \valid(nums + (0 .. nums_len-1));
    requires 0 <= left < nums_len;
    requires 0 <= right < nums_len;
    assigns nums[left], nums[right];
    ensures nums[left] == \old(nums[right]) && nums[right] == \old(nums[left]);
    ensures \forall integer i; 0 <= i < nums_len && i != left && i != right ==> nums[i] == \old(nums[i]);
*/
void swap(int * nums, int nums_len, int left, int right);

/*@ requires nums_len >= 0;
    requires \valid(nums + (0 .. nums_len-1));
    assigns nums[0..nums_len-1];
    ensures \let k = count_nonzero{Pre}(nums, nums_len);
            \forall integer i; 0 <= i < k ==> nums[i] != 0;
    ensures \let k = count_nonzero{Pre}(nums, nums_len);
            \forall integer i; k <= i < nums_len ==> nums[i] == 0;
    ensures \let k = count_nonzero{Pre}(nums, nums_len);
            \forall integer j; 0 <= j < k ==> 
               nums[j] == \at(nums[nth_nonzero_index{Pre}(nums, nums_len, j)], Pre);
*/
void moveZeroes(int * nums, int nums_len) {

        int n = nums_len, left = 0, right = 0;
        /*@
          loop invariant 0 <= left <= right <= n;
          loop invariant \valid(nums + (0 .. n-1));
          loop invariant left == count_nonzero{Pre}(nums, right);
          loop invariant \forall integer i; 0 <= i < left ==> nums[i] != 0;
          loop invariant \forall integer i; left <= i < right ==> nums[i] == 0;
          loop invariant \forall integer j; 0 <= j < left ==>
             nums[j] == \at(nums[nth_nonzero_index{Pre}(nums, n, j)], Pre);
          loop assigns left, right, nums[0..n-1];
          loop variant n - right;
        */
        while (right < n) {
            if (nums[right] != 0) {
                /*@ assert 0 <= left < nums_len; */
                /*@ assert 0 <= right < nums_len; */
                swap(nums, nums_len, left, right);
                left++;
            }
            right++;
        }
}

/*@ requires \valid(nums + (0 .. nums_len-1));
    requires 0 <= left < nums_len;
    requires 0 <= right < nums_len;
    assigns nums[left], nums[right];
    ensures nums[left] == \old(nums[right]) && nums[right] == \old(nums[left]);
    ensures \forall integer i; 0 <= i < nums_len && i != left && i != right ==> nums[i] == \old(nums[i]);
*/
void swap(int * nums, int nums_len, int left, int right) {

        int temp = nums[left];
        nums[left] = nums[right];
        nums[right] = temp;
}
