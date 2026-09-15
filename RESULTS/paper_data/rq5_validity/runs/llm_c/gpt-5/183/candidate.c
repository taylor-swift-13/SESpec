int countRotation(int * arr, int arr_len, int n);

/*@ 
  requires arr_len >= 0;
  requires n >= 0 && n <= arr_len;
  requires n == 0 || \valid_read(arr + (0 .. n-1));
  assigns \nothing;
  ensures n == 0 ==> \result == 0;
  ensures n > 0 ==> 1 <= \result <= n;
*/
int countRotation(int * arr, int arr_len, int n) {

        if (n == 0) {
            return 0;
        }
        int left = 0, right = n - 1;
        /*@
          loop invariant 0 <= left <= right <= n-1;
          loop invariant \valid_read(arr + (0 .. n-1));
          loop assigns left, right;
          loop variant right - left;
        */
        while (left < right) {
            /*@ assert 0 <= left <= n-1; */
            /*@ assert 0 <= right <= n-1; */
            if (arr[left] < arr[right]) {
                return left + 1;
            }
            int mid = (left + right) / 2;
            /*@ assert left < right ==> left <= mid < right; */
            /*@ assert 0 <= mid <= n-1; */
            if (arr[mid] > arr[left]) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return left + 1;
}
