
/*@
  // No additional logic functions are required.
*/

int foo236(int * arr, int arr_len, int x, int n) {

        int i = 0;
        int j = n - 1;
        int result = -1;

        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant n == n;
              loop invariant x == x;
              loop invariant arr == arr;
              loop invariant arr_len == arr_len;
              loop invariant -1 <= j <= n-1;
              loop invariant 0 <= i <= n;
              loop invariant i == 0 ==> j == n-1 ==> result == -1;
              loop invariant i > 0 ==> -1 <= j <= n-1;
              loop invariant result == -1 || (0 <= result < i);
              loop invariant i == 0 ==> result == -1;
              loop invariant i <= j + 1;
              loop assigns result, i, j;
            */
            while (i <= j) {
            int mid = (i + j) / 2;
            if (arr[mid] == x) {
                result = mid;
                i = mid + 1;
            } else if (arr[mid] < x) {
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }
            

        return result;
}
