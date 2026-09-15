
/*@
logic integer neq_count(int *a, integer l, integer u, int x) =
  l >= u ? 0 : ((a[l] != x) ? 1 : 0) + neq_count(a, l + 1, u, x);
*/

/*@
  requires 0 <= arr_len;
  requires arr_len > 1 ==> \valid_read(arr + (0 .. arr_len - 1));
*/

int foo241(int * arr, int arr_len, int n) {

        int count = 0;
        int length = arr_len;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= i <= length;
          loop invariant 0 <= count;
          loop assigns i, count;
            */
            for (int i = 0; i < length - 1; i++) {
            
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant i + 1 <= j <= length;
          loop invariant count >= 0;
          loop assigns j, count;
            */
            for (int j = i + 1; j < length; j++) {
                if (arr[i] != arr[j]) {
                    count++;
                }
            }
            
        }
            
        return count;
}
