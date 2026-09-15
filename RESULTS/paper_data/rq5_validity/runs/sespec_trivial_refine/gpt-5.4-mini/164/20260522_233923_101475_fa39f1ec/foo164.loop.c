
/*@
logic integer same_parity(integer x, integer y) = ((x ^ y) & 1) == 0;
*/

        /*@
        PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
        */
        
/*@
  requires arr != \null;
  requires \valid_read(arr + (0 .. arr_len - 1));
  requires 0 <= arr_len;
*/

int foo164(int * arr, int arr_len, int n) {

		if (arr == NULL) {
			return -1;
		}
		if (arr_len == 1) {
			return 0;
		}

		int evenPairCount = 0;
		
            /*@
          loop invariant 0 <= i <= arr_len;
          loop invariant evenPairCount == \numof integer x, y; 0 <= x < i && x < y < arr_len && same_parity(arr[x], arr[y]);
          loop assigns i, evenPairCount;
            */
            for (int i = 0; i < arr_len; i++) {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= i < arr_len;
          loop invariant 0 <= c <= arr_len;
          loop invariant evenPairCount >= 0;
          loop invariant evenPairCount == \numof integer x, y;
                            0 <= x < i &&
                            x < y < arr_len &&
                            same_parity(arr[x], arr[y])
                            +
                            \numof integer y;
                            i < y < c &&
                            same_parity(arr[i], arr[y]);
          loop assigns c, even, odd, z, evenPairCount;
            */
            for (int c = i + 1; c < arr_len; c++) {
				int even = arr[i];
				int odd = arr[c];
				int z = even ^ odd;
				if ((z & 1) == 0) {
					evenPairCount++;
				}
			}
            
		}
            
		return evenPairCount;
}
