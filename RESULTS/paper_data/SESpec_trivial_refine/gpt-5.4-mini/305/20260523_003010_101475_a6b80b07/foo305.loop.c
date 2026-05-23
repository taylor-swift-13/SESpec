
/*@
  requires n >= 0;
  requires n == 0 || \valid(arr + (0 .. n-1));
*/

int foo305(int * arr, int arr_len, int n) {

        int left = 0, right = n - 1;
        
            
        /*@
          loop invariant 0 <= left <= n;
          loop invariant -1 <= right < n;
          loop invariant left <= right + 1;
          loop assigns left, right;
        */
            while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] < arr[mid + 1]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
            
        return left;
}
