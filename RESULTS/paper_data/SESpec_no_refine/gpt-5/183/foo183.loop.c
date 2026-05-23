
/*@
  logic boolean unchanged_arr{L1,L2}(int *a, integer len) =
    \forall integer k; 0 <= k < len ==> \at(a[k],L1) == \at(a[k],L2);
*/

int foo183(int * arr, int arr_len, int n) {

        if (n == 0) {
            return 0;
        }
        int left = 0, right = n - 1;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= left <= right < n;
          loop invariant n == \at(n,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant unchanged_arr{Pre,Here}(arr, \at(arr_len,Pre));
          loop assigns left, right, mid;
            */
            while (left < right) {
            if (arr[left] < arr[right]) {
                return left + 1;
            }
            int mid = (left + right) / 2;
            if (arr[mid] > arr[left]) {
                left = mid;
            } else {
                right = mid;
            }
        }
            
        return left + 1;
}
