
/*@
  logic integer unchanged_array{L1,L2}(int* arr, integer len) =
    \forall integer i; 0 <= i < len ==> \at(arr[i],L1) == \at(arr[i],L2);
*/

/*@
  logic integer is_valid_left(int left, int n, int arr_len, int* arr) =
    0 <= left < n && arr == \at(arr,Pre) && n == \at(n,Pre) && arr_len == \at(arr_len,Pre);
*/

/*@
  logic integer is_valid_right(int right, int n, int arr_len, int* arr) =
    0 <= right < n && arr == \at(arr,Pre) && n == \at(n,Pre) && arr_len == \at(arr_len,Pre);
*/

/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
  assigns left, right, mid;
  ensures \result >= 1 && \result <= n;
  ensures unchanged_array{Pre,Here}(arr, arr_len);
*/
int foo38(int * arr, int arr_len, int n) {

    if (n == 0) {
        return 0;
    }
    int left = 0, right = n - 1;

    /*@
      loop invariant 0 <= left <= right < n;
      loop invariant n == \at(n,Pre);
      loop invariant arr_len == \at(arr_len,Pre);
      loop invariant arr == \at(arr,Pre);
      loop invariant unchanged_array{Pre,Here}(arr, arr_len);
      loop assigns left, right, mid;
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
