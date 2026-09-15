
/*@
  logic integer max_pref(int* a, integer lo, integer hi) =
    lo + 1 == hi ? a[lo]
    : (max_pref(a, lo, hi-1) > a[hi-1] ? max_pref(a, lo, hi-1) : a[hi-1]);
*/
/*@
  logic integer min_pref(int* a, integer lo, integer hi) =
    lo + 1 == hi ? a[lo]
    : (min_pref(a, lo, hi-1) < a[hi-1] ? min_pref(a, lo, hi-1) : a[hi-1]);
*/

/*@
  requires \at(arr_len,Pre) > 0 && \at(arr_len,Pre) < 100;
  requires \valid_read(arr + (0 .. arr_len-1));
  ensures \result == max_pref(arr, 0, arr_len) - min_pref(arr, 0, arr_len);
*/
int foo233(int * arr, int arr_len) {

    int result = arr[0];
    int num = arr[0];

    /*@
      loop invariant 1 <= n <= arr_len;
      loop invariant (n <= arr_len) ==> (result == max_pref(arr, 0, n));
      loop invariant (n <= arr_len) ==> (num == min_pref(arr, 0, n));
      loop invariant arr_len == \at(arr_len,Pre);
      loop invariant arr == \at(arr,Pre);
      loop invariant \forall integer i; 0 <= i < arr_len ==> arr[i] == \at(arr[i],Pre);
      loop assigns n, result, num;
    */
    for (int n = 1; n < arr_len; n++) {
        if (arr[n] > result) {
            result = arr[n];
        }
        if (arr[n] < num) {
            num = arr[n];
        }
    }

    return result - num;
}
