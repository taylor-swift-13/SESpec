
/*@
  logic integer max_in_range(int* arr, integer lo, integer hi) =
    lo >= hi ? arr[lo] : (arr[hi - 1] > max_in_range(arr, lo, hi - 1) ? arr[hi - 1] : max_in_range(arr, lo, hi - 1));

  logic integer min_in_range(int* arr, integer lo, integer hi) =
    lo >= hi ? arr[lo] : (arr[hi - 1] < min_in_range(arr, lo, hi - 1) ? arr[hi - 1] : min_in_range(arr, lo, hi - 1));
*/

int foo235(int * arr, int arr_len) {

    int result = arr[0];
    int sum = arr[0];

    /*@
      loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre);
      loop assigns n, result, sum;
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
