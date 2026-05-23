
/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);

  logic integer min_value{L}(int* a, integer lo, integer hi) =
    lo >= hi ? \max
             : \min(a[hi - 1], min_value(a, lo, hi - 1));
*/

int foo47(int n, int * arr, int arr_len) {

    if (n == 0) {
        return 0;
    }

    int min = arr[0];
    int count = 1;

    /*@
      loop invariant 1 <= i <= n;
      loop invariant min == min_value(arr, 0, i);
      loop invariant count == count_eq(arr, 0, i, min);
      loop invariant arr_len == \at(arr_len,Pre);
      loop invariant arr == \at(arr,Pre);
      loop invariant n == \at(n,Pre);
      loop assigns i, min, count;
    */
    for (int i = 1; i < n; i++) {
        if (min > arr[i]) {
            min = arr[i];
            count = 1;
        } else if (min == arr[i]) {
            count++;
        }
    }

    return count;
}
