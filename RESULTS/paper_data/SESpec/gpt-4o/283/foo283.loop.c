
/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  requires n >= 0;
  requires \valid(arr + (0 .. n-1));
  ensures \result == arr[n-1] || \exists integer k; 0 <= k < n-1 && arr[k] != arr[k+1] && \result == arr[k];
*/
int foo283(int * arr, int arr_len, int n) {

    int i = 0;

    /*@
      loop invariant 0 <= i <= n;
      loop invariant n == \at(n, Pre);
      loop invariant arr_len == \at(arr_len, Pre);
      loop invariant arr == \at(arr, Pre);
      loop invariant \forall integer k; 0 <= k < i ==> arr[k] == \at(arr[k], Pre);
      loop invariant \forall integer k; i <= k < n ==> arr[k] == \at(arr[k], Pre);
      loop invariant (0 < \at(n, Pre) - 1) ==> (i % 2 == 0);
      loop invariant (!(0 < \at(n, Pre) - 1)) ==> ((i == 0) && (n == \at(n, Pre)) && (arr_len == \at(arr_len, Pre)) && (arr == \at(arr, Pre)));
      loop assigns i;
    */
    while (i < n - 1) {
        if (arr[i] == arr[i + 1]) {
            i += 2;
        } else {
            return arr[i];
        }
    }

    return arr[n - 1];
}
