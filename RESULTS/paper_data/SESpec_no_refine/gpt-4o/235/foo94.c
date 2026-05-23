
/*@
  logic integer min(int* a, integer lo, integer hi) =
    lo >= hi ? a[lo] : (a[lo] < min(a, lo + 1, hi) ? a[lo] : min(a, lo + 1, hi));

  logic integer max(int* a, integer lo, integer hi) =
    lo >= hi ? a[lo] : (a[lo] > max(a, lo + 1, hi) ? a[lo] : max(a, lo + 1, hi));
*/

/*@
  requires \at(arr_len,Pre) > 0 && \at(arr_len,Pre) < 100;
  requires \valid(arr + (0..\at(arr_len,Pre)-1));
  assigns \nothing;
*/
int foo94(int * arr, int arr_len) {

    int result = arr[0];
    int sum = arr[0];

    /*@
      loop invariant 1 <= n <= \at(arr_len,Pre);
      loop invariant arr_len == \at(arr_len,Pre);
      loop invariant arr == \at(arr,Pre);
      loop assigns n, result, sum;
      loop variant \at(arr_len,Pre) - n;
    */
    for (int n = 1; n < arr_len; n++) {
        if (arr[n] > result) {
            result = arr[n];
        }
        if (arr[n] < sum) {
            sum = arr[n];
        }
    }

    return result - sum;
}
