
/*@
  logic integer sum_even_indices(int* arr, integer n) =
    n <= 0 ? 0 : sum_even_indices(arr, n - 1) + ((n - 1) % 2 == 0 && arr[n - 1] % 2 == 0 ? arr[n - 1] : 0);
*/

/*@
  requires n > 0 && n <= arr_len;
  requires arr_len > 0 && arr_len < 100;
  requires \valid(arr + (0 .. arr_len - 1));
  ensures \result == sum_even_indices(arr, n);
  assigns \nothing;
*/
int foo154(int * arr, int arr_len, int n) {

    int count = 0;

    /*@
      loop invariant 0 <= i <= n;
      loop invariant count == sum_even_indices(arr, i);
      loop invariant n == \at(n, Pre);
      loop invariant arr_len == \at(arr_len, Pre);
      loop invariant arr == \at(arr, Pre);
      loop assigns i, count;
      loop variant n - i;
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
