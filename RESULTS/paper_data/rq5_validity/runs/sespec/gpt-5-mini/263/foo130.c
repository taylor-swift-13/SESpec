
/*@
  predicate same_array{L1,L2}(int* a, integer len) =
    \forall integer i; 0 <= i < len ==> \at(a[i],L1) == \at(a[i],L2);
*/

/*@
  requires \valid(arr + (0 .. arr_len-1));
  requires \at(arr_len,Pre) > 0 && \at(arr_len,Pre) < 100;
  requires 0 <= n <= arr_len;
  assigns \nothing;
  ensures same_array{Pre,Here}(arr, arr_len);
  ensures (\result != -1) ==> (0 <= \result && \result < \at(n,Pre) && arr[\result] == \result);
*/
int foo130(int * arr, int arr_len, int n) {

    int start = 0;
    int end = n - 1;

    /*@
      loop invariant n == \at(n,Pre);
      loop invariant arr_len == \at(arr_len,Pre);
      loop invariant arr == \at(arr,Pre);
      loop invariant 0 <= start <= \at(n,Pre);
      loop invariant -1 <= end <= \at(n,Pre) - 1;
      loop invariant start <= \at(n,Pre);
      loop invariant end < \at(n,Pre);
      loop invariant same_array{Pre,Here}(arr, arr_len);
      loop assigns start, end;
    */
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == mid) {
            return mid;
        } else if (arr[mid] < mid) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    return -1;
}
