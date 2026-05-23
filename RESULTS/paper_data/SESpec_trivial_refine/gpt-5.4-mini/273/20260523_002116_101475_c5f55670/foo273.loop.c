
        /*@
        */
        
/*@
  requires 0 <= n;
  requires 0 <= arr_len;
  requires n <= arr_len;
  requires n == 0 || \valid_read(arr + (0 .. n - 1));
*/

int foo273(int * arr, int arr_len, int n) {

        int sum = 0;
        
        /*@
          loop invariant 0 <= i <= n;
          loop assigns i, sum, product;
        */
            for (int i = 0; i < n; i++) {
            int product = 1;
            
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= i <= n;
          loop invariant i <= j <= n;
          loop assigns j, product, sum;
            */
            for (int j = i; j < n; j++) {
                product *= arr[j];
                sum += product;
            }
            
        }
            
        return sum;
}
