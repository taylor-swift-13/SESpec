
/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  logic integer sorted{L}(int* a, integer lo, integer hi) =
    lo >= hi - 1 ? 1
                 : (a[lo] <= a[lo + 1] ? sorted(a, lo + 1, hi) : 0);
*/

/*@
  requires \valid(arr + (0..arr_len-1));
  requires arr_len > 0 && arr_len < 100;
  requires n > 0 && n <= arr_len;
  requires sorted(arr, 0, n);
  ensures \result == -1 || (0 <= \result < n && arr[\result] == x);
  ensures \forall integer i; 0 <= i < n && arr[i] == x ==> \result == i;
  assigns \nothing;
*/
int foo96(int * arr, int arr_len, int x, int n) {

    int low = 0;
    int high = n - 1;
    int result = -1;

    /*@
      loop invariant 0 <= low <= n;
      loop invariant -1 <= high < n;
      loop invariant -1 <= result < n;
      loop invariant result == -1 || arr[result] == x;
      loop invariant \forall integer i; 0 <= i < low ==> arr[i] < x;
      loop invariant \forall integer i; high < i < n ==> arr[i] > x;
      loop invariant sorted(arr, 0, n);
      loop invariant n == \at(n,Pre);
      loop invariant x == \at(x,Pre);
      loop invariant arr_len == \at(arr_len,Pre);
      loop invariant arr == \at(arr,Pre);
      loop assigns mid, result, high, low;
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
