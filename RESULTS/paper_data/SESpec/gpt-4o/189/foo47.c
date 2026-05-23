
/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  logic integer min_value{L}(int* a, integer lo, integer hi) =
    lo >= hi ? 2147483647
             : (a[hi - 1] < min_value(a, lo, hi - 1) ? a[hi - 1] : min_value(a, lo, hi - 1));
*/

/*@
  requires \at(n,Pre) > 0;
  requires \at(arr_len,Pre) > 0 && \at(arr_len,Pre) < 100;
  requires \valid(arr + (0 .. \at(arr_len,Pre) - 1));
  assigns \nothing;
*/
int foo47(int n, int * arr, int arr_len) {

    if (n == 0) {
        return 0;
    }

    int min = arr[0];
    int count = 1;

    /*@
      loop invariant arr_len == \at(arr_len,Pre);
      loop invariant arr == \at(arr,Pre);
      loop invariant n == \at(n,Pre);
      loop invariant 1 <= i <= n;
      loop invariant min == min_value(arr, 0, i);
      loop invariant \forall integer k; 0 <= k < i ==> arr[k] >= min; // Ensure min is the smallest value seen so far
      loop assigns i, min, count;
      loop variant n - i;
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
