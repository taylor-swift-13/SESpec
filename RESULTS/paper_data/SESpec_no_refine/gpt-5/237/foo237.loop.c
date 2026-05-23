
/*@
  // Valid-read slice for first n elements
  predicate valid_read_slice(int *a, integer n) =
    n >= 0 ==> \valid_read(a + (0 .. (n > 0 ? n-1 : -1)));

  // Binary-search partition: elements before low are < x; elements after high are > x
  predicate bs_partition(int *a, integer lo, integer hi, integer x, integer n) =
    0 <= lo && lo <= n && -1 <= hi && hi < n &&
    (\forall integer k; 0 <= k < lo ==> a[k] < x) &&
    (\forall integer k; hi < k < n ==> a[k] > x);
*/

int foo237(int * arr, int arr_len, int x, int n) {

        int low = 0;
        int high = n - 1;
        int result = -1;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant n == \at(n,Pre);
          loop invariant x == \at(x,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
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
