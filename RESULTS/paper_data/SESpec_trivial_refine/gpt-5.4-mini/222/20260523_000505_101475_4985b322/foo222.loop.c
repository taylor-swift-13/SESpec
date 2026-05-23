
/*@
predicate odd_xor(int a, int b) = ((a ^ b) % 2) == 1;
*/

/*@
  requires 0 <= arr_len;
  requires \valid_read(arr + (0 .. arr_len-1));
*/

int foo222(int * arr, int arr_len, int n) {

		int result = 0;
		int offset = arr_len;
		
            /*@
          loop invariant 0 <= index && index <= offset;
          loop invariant result >= 0;
          loop assigns result, index;
            */
            for (int index = 0; index < offset; index++) {
			
            /*@
          loop invariant 0 <= index && index <= offset;
          loop invariant result >= 0;
          loop assigns result;
            */
            for (int c = index + 1; c < offset; c++) {
				if ((arr[index] ^ arr[c]) % 2 == 1) {
					result++;
				}
			}
            
		}
            
		return result;
}
