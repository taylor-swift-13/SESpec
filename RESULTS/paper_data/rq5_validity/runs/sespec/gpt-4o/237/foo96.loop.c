
/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  logic integer sorted{L}(int* a, integer lo, integer hi) =
    lo >= hi - 1 ? 1 : ((a[lo] <= a[lo + 1] ? 1 : 0) && sorted(a, lo + 1, hi) ? 1 : 0);
*/

/*@
  logic integer in_range{L}(int* a, integer lo, integer hi, integer x) =
    lo >= hi ? 0 : ((a[lo] == x ? 1 : 0) + in_range(a, lo + 1, hi, x));
*/

/*@
  requires \valid(arr + (0 .. arr_len - 1));
  requires arr_len > 0 && arr_len < 100;
  requires n >= 0;
  requires \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre);
*/
int foo96(int * arr, int arr_len, int x, int n) {

    int low = 0;
    int high = n - 1;
    int result = -1;

    /*@
      loop invariant 0 <= low && low <= n && n >= 0;
      loop invariant -1 <= high && high < n;
      loop invariant -1 <= result && result < n;
      loop invariant n == \at(n,Pre);
      loop invariant x == \at(x,Pre);
      loop invariant arr_len == \at(arr_len,Pre);
      loop invariant arr == \at(arr,Pre);
      loop invariant \forall integer k; 0 <= k < n ==> (arr[k] == \at(arr[k], Pre));
      loop invariant (result != -1) ==> (arr[result] == x);
      loop assigns low, high, result;
    */
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == x) {
            result = mid;
            high = mid - 1;
        } else if (arr[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return result;
}
