
/*@
  predicate unchanged_array{L1,L2}(int* arr, integer len) =
    \forall integer i; 0 <= i < len ==> \at(arr[i],L1) == \at(arr[i],L2);
*/

/*@
  predicate is_left_valid(int left, int n) =
    0 <= left <= n - 1;
*/

/*@
  predicate is_right_valid(int right, int n) =
    0 <= right <= n - 1;
*/

int foo208(int * arr, int arr_len, int n) {

        int left = 0, right = n - 1;

        /*@
          loop invariant (0 < \at(n,Pre) - 1) ==> 
            (((right == \at(n,Pre) - 1) && (left == 0) && (n == \at(n,Pre)) && 
              (arr_len == \at(arr_len,Pre)) && (arr == \at(arr,Pre))) || 
             is_left_valid(left, n));
          loop invariant (0 < \at(n,Pre) - 1) ==> 
            (((right == \at(n,Pre) - 1) && (left == 0) && (n == \at(n,Pre)) && 
              (arr_len == \at(arr_len,Pre)) && (arr == \at(arr,Pre))) || 
             is_right_valid(right, n));
          loop invariant (!(0 < \at(n,Pre) - 1)) ==> 
            ((right == \at(n,Pre) - 1) && (left == 0) && (n == \at(n,Pre)) && 
             (arr_len == \at(arr_len,Pre)) && (arr == \at(arr,Pre)));
          loop invariant n == \at(n,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant unchanged_array{Pre,Here}(arr, arr_len);
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
