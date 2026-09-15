
/*@
  axiomatic PairCount {
    logic integer count_pairs{L}(int *arr, integer n, integer sum)
      reads arr[0 .. n - 1];
  }
*/

/*@
  requires 0 <= n <= arr_len;
  requires arr_len <= 0 || \valid_read(arr + (0 .. arr_len - 1));
  assigns \nothing;
  ensures 0 <= \result <= n * (n - 1) / 2;
  ensures n <= 1 ==> \result == 0;
*/
int foo252(int *arr, int arr_len, int n, int sum) {
  int count = 0;

  /*@
    loop invariant 0 <= i <= n;
    loop invariant 0 <= count <= i * (2 * n - i - 1) / 2;
    loop assigns i, count;
    loop variant n - i;
  */
  for (int i = 0; i < n; i++) {

    /*@
      loop invariant i + 1 <= j <= n;
      loop invariant 0 <= count <= i * (2 * n - i - 1) / 2 + (j - (i + 1));
      loop assigns j, count;
      loop variant n - j;
    */
    for (int j = i + 1; j < n; j++) {
      if (arr[i] + arr[j] == sum) {
        count++;
      }
    }
  }

  return count;
}
