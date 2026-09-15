
/*@
  logic integer sum_even_indices(int* arr, integer n) =
    n <= 0 ? 0 : sum_even_indices(arr, n - 1) + ((n - 1) % 2 == 0 && arr[n - 1] % 2 == 0 ? arr[n - 1] : 0);
*/

/*@
  requires \at(arr_len, Pre) > 0 && \at(arr_len, Pre) < 100;
  requires \valid(arr + (0 .. \at(arr_len, Pre) - 1));
  ensures \result == sum_even_indices(arr, n);
*/
int foo154(int * arr, int arr_len, int n) {

    int count = 0;

    /*@
      loop invariant n == \at(n, Pre);
      loop invariant arr_len == \at(arr_len, Pre);
      loop invariant arr == \at(arr, Pre);
      loop assigns i, count;
    */
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            if (arr[i] % 2 == 0) {
                count += arr[i];
            }
        }
    }

    return count;
}
