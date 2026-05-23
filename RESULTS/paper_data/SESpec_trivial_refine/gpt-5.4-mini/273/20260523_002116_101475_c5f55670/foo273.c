
        /*@
        */
        
/*@ logic integer prod_range(int *arr, integer i, integer j) =
      i > j ? 1 : arr[i] * prod_range(arr, i + 1, j); */
/*@ logic integer suffix_prod_sum(int *arr, integer i, integer j) =
      j < i ? 0 : prod_range(arr, i, j) + suffix_prod_sum(arr, i, j - 1); */
/*@ logic integer foo273_spec(int *arr, integer n) =
      n <= 0 ? 0 : foo273_spec(arr, n - 1) + suffix_prod_sum(arr, n - 1, n - 1); */
/*@
  requires 0 <= n;
  requires 0 <= arr_len;
  requires n <= arr_len;
  requires n == 0 || \valid_read(arr + (0 .. n - 1));
  assigns \nothing;
  ensures \result == foo273_spec(arr, n);
  ensures n == 0 ==> \result == 0;
  ensures n > 0 ==> \result == foo273_spec(arr, n);
  ensures \result == \null ==> \false;
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
