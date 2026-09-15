
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

/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
  assigns left, right;
  ensures unchanged_array{Pre,Post}(arr, arr_len);
  ensures \result >= 0 && \result < arr_len;
  ensures (\result > 0 ==> arr[\result] >= arr[\result - 1]) && (\result < arr_len - 1 ==> arr[\result] >= arr[\result + 1]);
*/
int foo208(int * arr, int arr_len, int n) {

        int left = 0, right = n - 1;
        
        /*@
          loop invariant left >= 0 && right >= 0 && left < arr_len && right < arr_len;
          loop invariant left <= right;
          loop invariant n == \at(n,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant unchanged_array{Pre,Here}(arr, arr_len);
          loop assigns left, right, mid;
          loop variant right - left;
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
