
/*@
  logic integer max_in_range(int* arr, integer lo, integer hi) =
    lo == hi ? arr[lo] : (arr[hi - 1] > max_in_range(arr, lo, hi - 1) ? arr[hi - 1] : max_in_range(arr, lo, hi - 1));
*/

/*@
  logic integer min_in_range(int* arr, integer lo, integer hi) =
    lo == hi ? arr[lo] : (arr[hi - 1] < min_in_range(arr, lo, hi - 1) ? arr[hi - 1] : min_in_range(arr, lo, hi - 1));
*/

/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires arr_len > 0;
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  assigns \nothing;
  ensures \forall integer i; 0 <= i < arr_len ==> arr[i] == \at(arr[i], Pre);
  ensures \result == max_in_range(arr, 0, arr_len - 1) - min_in_range(arr, 0, arr_len - 1);
  ensures \result >= 0;
*/
int foo235(int * arr, int arr_len) {

    int result = arr[0];
    int sum = arr[0];

    /*@
      loop invariant 1 <= n <= arr_len;
      loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre);
      loop invariant \forall integer i; 0 <= i < n ==> result >= arr[i];
      loop invariant \forall integer i; 0 <= i < n ==> sum <= arr[i];
      loop invariant result == (n > 1 ? max_in_range(arr, 0, n - 2) : arr[0]) || result == arr[n - 1];
      loop invariant sum == (n > 1 ? min_in_range(arr, 0, n - 2) : arr[0]) || sum == arr[n - 1];
      loop assigns result, sum;
      loop variant arr_len - n;
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
