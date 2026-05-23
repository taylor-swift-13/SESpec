
/*@ 
  predicate unchanged_array{L1,L2}(int *a, integer len) =
    \forall integer k; 0 <= k < len ==> \at(a[k],L1) == \at(a[k],L2);
*/
        
int foo305(int * arr, int arr_len, int n) {

        int left = 0, right = n - 1;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= left <= \at(n,Pre) - 1;
          loop invariant 0 <= right <= \at(n,Pre) - 1;
          loop invariant left <= right;
          loop invariant n == \at(n,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant unchanged_array(arr, arr_len);
          loop assigns mid, left, right;
            */
            while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] < arr[mid + 1]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
            
        return left;
}
