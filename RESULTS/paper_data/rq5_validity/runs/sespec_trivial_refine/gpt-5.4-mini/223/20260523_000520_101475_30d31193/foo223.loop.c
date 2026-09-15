
/*@ logic boolean odd(integer x) = x % 2 != 0; */

        
/*@
  requires arr_len >= 0;
  requires arr_len == 0 || \valid_read(arr + (0 .. arr_len - 1));
*/

int foo223(int * arr, int arr_len, int n) {

		int result = 0;
		int offset = arr_len;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= c <= offset;
          loop assigns c, result;
            */
            for (int c = 0; c < offset; c++) {
			
            /*@
          loop invariant 0 <= c <= offset;
          loop invariant result >= 0;
          loop assigns c, result;
            */
            /*@
          loop invariant c + 1 <= index <= offset;
          loop invariant result >= 0;
          loop assigns index, result;
            */
            for (int index = c + 1; index < offset; index++) {
				if ((arr[c] ^ arr[index]) % 2 == 1) {
					result++;
				}
			}
            
		}
            
		return result;
}
