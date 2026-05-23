
/*@
  requires n >= 0;
  requires arr_len >= n;
  requires \valid_read(arr + (0 .. arr_len - 1));
*/

int foo274(int * arr, int arr_len, int n) {

        int count = 0;
        
        /*@
          loop invariant 0 <= i <= n;
          loop invariant count == \sum(integer k = 0; k < i; (k % 2 == 0 && arr[k] % 2 == 0) ? arr[k] : 0);
          loop assigns count, i;
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
