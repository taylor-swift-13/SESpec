
/*@
  predicate unchanged_array{L1,L2}(int* arr, integer len) =
    \forall integer i; 0 <= i < len ==> \at(arr[i],L1) == \at(arr[i],L2);
*/

/*@
  predicate is_left_valid(integer left, integer n, integer arr_len) =
    (0 <= left && left < n) && (arr_len > 0 && arr_len < 100);
*/

/*@
  predicate is_right_valid(integer right, integer n, integer arr_len) =
    (0 <= right && right < n) && (arr_len > 0 && arr_len < 100);
*/

/*@
  predicate valid_range(int* arr, integer left, integer right) =
    \forall integer i; left <= i <= right ==> \valid(arr + i);
*/

/*@
  logic integer mid_value(integer left, integer right) = (left + right) / 2;
*/
/*@
  requires n > 0;
  requires arr_len > 0 && arr_len < 100;
  requires \valid(arr + (0 .. n-1));
  ensures \result >= 1 && \result <= n;
  ensures unchanged_array{Pre,Post}(arr, arr_len);
  ensures \exists integer left, right; 
           0 <= left <= right < n &&
           valid_range(arr, left, right) &&
           (arr[left] < arr[right] ==> \result == left + 1);
  assigns \nothing;
*/
int foo38(int * arr, int arr_len, int n) {

        if (n == 0) {
            return 0;
        }
        int left = 0, right = n - 1;
        
        /*@
          loop invariant 0 <= left && left <= right && right < n;
          loop invariant valid_range(arr, left, right);
          loop invariant n == \at(n,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant unchanged_array{Pre,Here}(arr, arr_len);
          loop assigns left, right;
          loop variant right - left;
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
