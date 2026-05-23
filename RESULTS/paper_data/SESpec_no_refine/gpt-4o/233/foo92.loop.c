
/*@
  logic integer max_in_range(int* arr, integer lo, integer hi) =
    lo >= hi ? arr[lo] : (arr[hi - 1] > max_in_range(arr, lo, hi - 1) ? arr[hi - 1] : max_in_range(arr, lo, hi - 1));

  logic integer min_in_range(int* arr, integer lo, integer hi) =
    lo >= hi ? arr[lo] : (arr[hi - 1] < min_in_range(arr, lo, hi - 1) ? arr[hi - 1] : min_in_range(arr, lo, hi - 1));
*/

/*@
  requires \valid(arr + (0 .. arr_len - 1));
  requires arr_len > 0 && arr_len < 100;
  ensures \result == max_in_range(arr, 0, arr_len) - min_in_range(arr, 0, arr_len);
*/
int foo92(int * arr, int arr_len) {

    int result = arr[0];
    int num = arr[0];

    /*@
      loop invariant 1 <= n <= arr_len;
      loop invariant result == max_in_range(arr, 0, n);
      loop invariant num == min_in_range(arr, 0, n);
      loop invariant arr_len == \at(arr_len, Pre);
      loop invariant arr == \at(arr, Pre);
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
