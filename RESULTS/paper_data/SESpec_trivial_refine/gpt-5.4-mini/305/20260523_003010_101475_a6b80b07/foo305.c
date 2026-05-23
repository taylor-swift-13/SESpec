
/*@
  requires n > 0;
  requires \valid_read(arr + (0 .. n-1));
  assigns \nothing;
  ensures 0 <= \result < n;
*/
int foo305(int *arr, int arr_len, int n) {
    int left = 0, right = n - 1;

    /*@
      loop invariant 0 <= left < n;
      loop invariant -1 <= right < n;
      loop invariant left <= right + 1;
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
