
/*@
  logic integer max_in_prefix(int* arr, integer len) =
    len <= 0 ? arr[0] : (arr[len - 1] > max_in_prefix(arr, len - 1) ? arr[len - 1] : max_in_prefix(arr, len - 1));

  logic integer min_in_prefix(int* arr, integer len) =
    len <= 0 ? arr[0] : (arr[len - 1] < min_in_prefix(arr, len - 1) ? arr[len - 1] : min_in_prefix(arr, len - 1));
*/

int foo234(int * arr, int arr_len) {

    int big = arr[0];
    int sum = arr[0];

    /*@
      loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre);
      loop assigns n, big, sum;
    */
    for (int n = 1; n < arr_len; n++) {
        if (arr[n] > big) {
            big = arr[n];
        }
        if (arr[n] < sum) {
            sum = arr[n];
        }
    }

    return big - sum;
}
