int findPeak(int * arr, int arr_len, int n);

/*@ predicate is_peak(int *a, integer n, integer i) =
      0 <= i < n
      && ((i == 0) || a[i] >= a[i-1])
      && ((i == n-1) || a[i] >= a[i+1]);
*/

/*@ requires n > 0;
    requires 0 <= n <= arr_len;
    requires \valid_read(arr + (0..n-1));
    assigns \nothing;
    ensures 0 <= \result < n;
    ensures is_peak(arr, n, \result);
*/
int findPeak(int * arr, int arr_len, int n) {

        int left = 0, right = n - 1;
        /*@ 
          loop invariant 0 <= left <= right < n;
          loop invariant \exists integer p; left <= p <= right && is_peak(arr, n, p);
          loop assigns left, right;
          loop variant right - left;
        */
        while (left < right) {
            int mid = left + (right - left) / 2;
            /*@ assert left <= mid < right; */
            /*@ assert 0 <= mid && mid + 1 < n; */
            if (arr[mid] < arr[mid + 1]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
}
