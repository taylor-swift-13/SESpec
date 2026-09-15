
        /*@
        */
        
/*@
  requires 0 <= arr_len;
  requires arr_len == 0 || \valid_read(arr + (0 .. arr_len - 1));
*/

int foo275(int * arr, int arr_len, int n) {

        int sum = 0;
        
        /*@
          loop invariant 0 <= i && i <= arr_len;
          loop assigns i, sum;
        */
        for (int i = 0; i < arr_len; i++) {
            
            
            /*@
          loop invariant 0 <= i && i < arr_len;
          loop invariant i + 1 <= j && j <= arr_len;
          loop assigns sum, j;
            */
            for (int j = i + 1; j < arr_len; j++) {
                sum += arr[i] ^ arr[j];
            }
            
        }
            
        return sum;
}
