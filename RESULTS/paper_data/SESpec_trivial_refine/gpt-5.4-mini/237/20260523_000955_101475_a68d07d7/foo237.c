
        /*@
        predicate sorted{L}(int *a, integer n) =
          \forall integer i, j; 0 <= i <= j < n ==> a[i] <= a[j];
        */

/*@
  requires 0 <= n <= arr_len;
  requires arr_len == 0 || \valid_read(arr + (0 .. arr_len-1));
  assigns \nothing;
  ensures -1 <= \result;
  ensures \result < n;
  ensures \result != -1 ==> arr[\result] == x;
*/
int foo237(int * arr, int arr_len, int x, int n) {

        int low = 0;
        int high = n - 1;
        int result = -1;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= low;
          loop invariant high < n;
          loop invariant result == -1 || (0 <= result < n && arr[result] == x);
          loop assigns low, high, result;
            */
            while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] == x) {
                result = mid;
                high = mid - 1;
            } else if (arr[mid] < x) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
            
        return result;
}
