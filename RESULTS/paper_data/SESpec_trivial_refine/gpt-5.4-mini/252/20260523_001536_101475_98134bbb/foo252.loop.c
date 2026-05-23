
/*@
        predicate is_match(integer a, integer b, integer s) = a + b == s;
        */

/*@
  requires 0 <= n <= arr_len;
  requires arr_len <= 0 || \valid_read(arr + (0 .. arr_len - 1));
*/

int foo252(int * arr, int arr_len, int n, int sum) {

        int count = 0;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= count;
          loop invariant 0 <= i <= n;
          loop assigns i, count;
            */
            for (int i = 0; i < n; i++) {
            
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= i <= n;
          loop invariant 0 <= count;
          loop invariant i + 1 <= j <= n;
          loop assigns count, j;
            */
            for (int j = i + 1; j < n; j++) {
                if (arr[i] + arr[j] == sum) {
                    count++;
                }
            }
            
        }
            
        return count;
}
