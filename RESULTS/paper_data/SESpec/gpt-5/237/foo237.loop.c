
/*@
  predicate sorted_non_decr(int* a, integer n) =
    \forall integer i,j; 0 <= i <= j < n ==> a[i] <= a[j];
*/

/*@
  requires 0 <= arr_len;
  requires \valid_read(arr + (0..arr_len-1));
  requires 0 <= n && n <= arr_len;
  requires sorted_non_decr(arr, n);
*/
int foo237(int * arr, int arr_len, int x, int n) {

        int low = 0;
        int high = n - 1;
        int result = -1;

            /*@
          loop invariant \valid_read(arr + (0..arr_len-1));
          loop invariant 0 <= arr_len;
          loop invariant 0 <= n && n <= arr_len;

          loop invariant n == \at(n,Pre);
          loop invariant x == \at(x,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre);

          loop invariant sorted_non_decr(arr, n);

          loop invariant 0 <= low && low <= n;
          loop invariant -1 <= high && high <= n - 1;
          loop invariant low <= high + 1;

          loop invariant (result == -1) || (0 <= result && result < n);
          loop invariant (result == -1) || (arr[result] == x);
          loop invariant (result == -1) || (high < result);

          loop assigns result, high, low;
            */
            while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] == x) {
                result = mid;
                high = mid - 1;
            } else if (arr[mid] < x) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return result;
}
