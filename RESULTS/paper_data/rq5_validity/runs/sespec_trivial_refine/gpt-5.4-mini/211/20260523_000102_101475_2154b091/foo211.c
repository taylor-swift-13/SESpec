

/*@ predicate valid_arr_prefix{L}(int *a, integer n) =
      n <= 0 || \valid_read(a + (0 .. n-1));
*/

/*@
  requires valid_arr_prefix(arr, n);
  requires 0 <= n;
  requires n <= arr_len;
  assigns \nothing;
  ensures \result >= 0;
  ensures \result <= n;
  ensures n == 0 ==> \result == 0;
*/
int foo211(int * arr, int arr_len, int n) {

        int count = 0;
        int i = 0;
        int j = 1;

        /*@
          loop invariant 0 <= i <= n;
          loop invariant 1 <= j <= n + 1;
          loop invariant 0 <= count;
          loop invariant count <= i;
          loop invariant count <= j - 1;
          loop assigns i, j, count;
          loop variant n - i + n - j;
        */
        while (i < n && j < n) {
            if (arr[i] == arr[j]) {
                i++;
                j++;
                count++;
            } else if (arr[i] > arr[j]) {
                i++;
            } else {
                j++;
            }
        }

        return count;
}
