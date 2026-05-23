
/*@
  predicate unchanged_array{L1,L2}(int* arr, integer len) =
    \forall integer i; 0 <= i < len ==> \at(arr[i],L1) == \at(arr[i],L2);
*/

/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
  requires n > 0;
  requires n <= arr_len;
  requires \exists integer i; 0 <= i < n &&
            (i == 0 || arr[i] >= arr[i - 1]) &&
            (i == n - 1 || arr[i] >= arr[i + 1]);
  assigns \nothing;
  ensures 0 <= \result < n;
  ensures unchanged_array{Pre,Post}(arr, arr_len);
*/
int foo208(int * arr, int arr_len, int n) {

        int left = 0, right = n - 1;

        /*@
          loop invariant 0 <= left && left <= right && right < n;
          loop invariant n == \at(n,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant unchanged_array{Pre,Here}(arr, arr_len);
          loop assigns left, right;
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
