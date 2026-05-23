
/*@
  logic integer unchanged_array{L1,L2}(int* arr, integer len) =
    \forall integer i; 0 <= i < len ==> \at(arr[i],L1) == \at(arr[i],L2);
*/

/*@
  logic integer is_left_progressing(int left, int prev_left) =
    left >= prev_left;
*/

/*@
  logic integer is_right_progressing(int right, int prev_right) =
    right <= prev_right;
*/

int foo208(int * arr, int arr_len, int n) {

        int left = 0, right = n - 1;
        
        /*@
          loop invariant (0 < \at(n,Pre) - 1) ==> (((right == \at(n,Pre) - 1)&&(left == 0)&&(n == \at(n,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))) || (left >=0 ));
          loop invariant (0 < \at(n,Pre) - 1) ==> (((right == \at(n,Pre) - 1)&&(left == 0)&&(n == \at(n,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))) || (right >=0 ));
          loop invariant (!(0 < \at(n,Pre) - 1)) ==> ((right == \at(n,Pre) - 1)&&(left == 0)&&(n == \at(n,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre)));
          loop invariant n == \at(n,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant unchanged_array{Pre,Here}(arr, arr_len);
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
