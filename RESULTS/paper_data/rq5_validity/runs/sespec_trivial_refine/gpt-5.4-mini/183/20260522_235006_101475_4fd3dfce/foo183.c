
/*@
  requires n >= 0;
  requires n == 0 || \valid_read(arr + (0 .. n - 1));
  assigns \nothing;
  ensures n == 0 <==> \result == 0;
  ensures n > 0 ==> (1 <= \result && \result <= n);
*/
int foo183(int * arr, int arr_len, int n) {

        if (n == 0) {
            return 0;
        }
        int left = 0, right = n - 1;

        /*@
          loop invariant 0 <= left <= right < n;
          loop assigns left, right;
          loop variant right - left;
        */
        while (left < right) {
            if (arr[left] < arr[right]) {
                return left + 1;
            }
            int mid = (left + right) / 2;
            if (arr[mid] > arr[left]) {
                left = mid;
            } else {
                right = mid;
            }
        }

        return left + 1;
}
