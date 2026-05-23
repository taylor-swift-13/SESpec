
/*@
axiomatic ArrayExtrema {
  logic integer max_arr{L}(int *arr, integer n) =
    (n == 1 ? arr[0] :
      (arr[n-1] > max_arr(arr, n-1) ? arr[n-1] : max_arr(arr, n-1)));

  logic integer min_arr{L}(int *arr, integer n) =
    (n == 1 ? arr[0] :
      (arr[n-1] < min_arr(arr, n-1) ? arr[n-1] : min_arr(arr, n-1)));
}
*/

/*@
  requires arr_len > 0;
  requires \valid_read(arr + (0 .. arr_len-1));
  assigns \nothing;
  ensures \result == max_arr(arr, arr_len) - min_arr(arr, arr_len);
  ensures \result >= 0;
*/
int foo233(int *arr, int arr_len) {

    int result = arr[0];
    int num = arr[0];

    /*@
      loop invariant 1 <= n <= arr_len;
      loop invariant result == max_arr(arr, n);
      loop invariant num == min_arr(arr, n);
      loop assigns n, result, num;
      loop variant arr_len - n;
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
