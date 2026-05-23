
/*@ 
  predicate unchanged_arr(int *a, integer len, int *a_pre) =
    \forall integer k; 0 <= k < len ==> a[k] == a_pre[k];
*/
        
int foo38(int * arr, int arr_len, int n) {

        if (n == 0) {
            return 0;
        }
        int left = 0, right = n - 1;
        
            
        /*@
          loop invariant left == 0 || (\exists integer L; 0 < L <= \at(n,Pre) - 1 && 0 <= L <= right && left == L);
          loop invariant right == \at(n,Pre) - 1 || (\exists integer R; 0 <= R < \at(n,Pre) - 1 && left <= R && right == R);
          loop invariant (!(0 < \at(n,Pre) - 1)) ==> ((right == \at(n,Pre) - 1)&&(left == 0)&&(n == \at(n,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre)));
          loop invariant n == \at(n,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant unchanged_arr(arr, arr_len, \at(arr,Pre));
          loop assigns left, right;
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
