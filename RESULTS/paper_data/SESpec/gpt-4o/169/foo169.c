
/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  predicate sorted(int* a, integer lo, integer hi) =
    \forall integer i, j; lo <= i <= j < hi ==> a[i] <= a[j];
*/

/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
*/
int foo169(int * arr, int arr_len) {

    int r = 0;
    int stop = arr_len - 1;

    /*@
      loop invariant arr_len == \at(arr_len, Pre);
      loop invariant arr == \at(arr, Pre);
      loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre);
      loop assigns r, stop;
      loop variant stop - r;
    */
    while (r <= stop) {
        int i = r + (stop - r) / 2;
        if (i < stop && arr[i] > arr[i + 1]) {
            return i + 1;
        } else if (i > r && arr[i] < arr[i - 1]) {
            return i;
        }
        if (arr[i] >= arr[r]) {
            r = i + 1;
        } else {
            stop = i - 1;
        }
    }

    return 0;
}
