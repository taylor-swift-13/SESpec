
/*@
logic integer pair_count{L}(int *arr, integer n, integer k) reads arr[0 .. n-1] =
  (k <= 0 ? 0 :
   pair_count(arr, n, k - 1) +
   (\sum integer j = k; j < n; j++ ((arr[k - 1] ^ arr[j]) % 2 == 1 ? 1 : 0)));
*/
/*@
logic integer pair_count{L}(int *arr, integer n, integer k) reads arr[0 .. n-1] =
  (k <= 0 ? 0 :
   pair_count(arr, n, k - 1) +
   (\sum integer j = k; j < n; ((arr[k - 1] ^ arr[j]) % 2 == 1 ? 1 : 0)));
*/

        /*@
        \true
        */
        
/*@
  requires 0 <= arr_len;
  requires \valid_read(arr + (0 .. arr_len - 1));
*/

int foo221(int * arr, int arr_len, int n) {

		int found = 0;
		int offset = arr_len;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant \true;
          loop invariant 0 <= c <= offset;
          loop invariant found == pair_count(arr, offset, c);
            */
            for (int c = 0; c < offset; c++) {
			
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= c <= offset;
          loop invariant found == pair_count(arr, offset, c);
          loop invariant \true;
          loop invariant c + 1 <= index <= offset;
          loop invariant found == pair_count(arr, offset, c) + (\sum integer j = c + 1; j < index; ((arr[c] ^ arr[j]) % 2 == 1 ? 1 : 0));
          loop assigns index, found;
            */
            for (int index = c + 1; index < offset; index++) {
				if ((arr[c] ^ arr[index]) % 2 == 1) {
					found++;
				}
			}
            
		}
            
		return found;
}
