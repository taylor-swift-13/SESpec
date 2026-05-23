
/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

int foo263(int * arr, int arr_len, int n) {

    int start = 0;
    int end = n - 1;

    /*@
      loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre);
      loop invariant \exists integer k; start <= k <= end ==> arr[k] == k;
      loop invariant n == \at(n, Pre);
      loop invariant arr_len == \at(arr_len, Pre);
      loop invariant arr == \at(arr, Pre);
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
