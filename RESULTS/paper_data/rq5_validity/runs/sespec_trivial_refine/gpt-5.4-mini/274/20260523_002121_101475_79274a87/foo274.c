
/*@
  requires n >= 0;
  requires arr_len >= n;
  requires \valid_read(arr + (0 .. arr_len - 1));
  assigns \nothing;
*/
int foo274(int *arr, int arr_len, int n) {

    int count = 0;

    /*@
      loop invariant 0 <= i <= n;
      loop assigns count, i;
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
