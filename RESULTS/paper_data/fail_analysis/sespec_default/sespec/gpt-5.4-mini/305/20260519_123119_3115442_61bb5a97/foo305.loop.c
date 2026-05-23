
/*@
  predicate unchanged_array{L1, L2}(int *a, integer n) =
    \forall integer i; 0 <= i < n ==> \at(a[i], L1) == \at(a[i], L2);
*/
        
int foo305(int * arr, int arr_len, int n) {

        int left = 0, right = n - 1;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= left;
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant unchanged_array{Pre, Here}(arr, arr_len);
          loop assigns left, right;
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
