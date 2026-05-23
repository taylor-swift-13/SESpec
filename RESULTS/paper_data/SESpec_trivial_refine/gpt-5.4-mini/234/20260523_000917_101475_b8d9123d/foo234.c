
/*@
  axiomatic ArrayExtrema {
    logic integer max_array{L}(int *arr, integer n);
    logic integer min_array{L}(int *arr, integer n);

    axiom max_array_lower_bound:
      \forall int *arr, integer n, integer i;
        n > 0 && 0 <= i < n ==> max_array(arr, n) >= arr[i];

    axiom max_array_exists:
      \forall int *arr, integer n;
        n > 0 ==> \exists integer i; 0 <= i < n && max_array(arr, n) == arr[i];

    axiom min_array_upper_bound:
      \forall int *arr, integer n, integer i;
        n > 0 && 0 <= i < n ==> min_array(arr, n) <= arr[i];

    axiom min_array_exists:
      \forall int *arr, integer n;
        n > 0 ==> \exists integer i; 0 <= i < n && min_array(arr, n) == arr[i];
  }
*/

/*@
  requires arr_len > 0;
  requires \valid_read(arr + (0 .. arr_len - 1));
  assigns \nothing;
  ensures \result >= 0;
  ensures arr_len == 1 ==> \result == 0;
*/
int foo234(int *arr, int arr_len) {
  int big = arr[0];
  int sum = arr[0];

  /*@
    loop invariant 1 <= n <= arr_len;
    loop invariant \forall integer i; 0 <= i < n ==> big >= arr[i];
    loop invariant \forall integer i; 0 <= i < n ==> sum <= arr[i];
    loop invariant big >= sum;
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

  if (arr_len == 1) {
    return 0;
  }

  return big - sum;
}
