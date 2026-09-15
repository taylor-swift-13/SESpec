/*@
    requires arr_len >= 0;
    requires arr_len == 0 || \valid_read(arr + (0 .. arr_len - 1));
    assigns \nothing;
    ensures \result >= 0;
*/
int findOddPair(int * arr, int arr_len, int n);

 /*@
    requires arr_len >= 0;
    requires arr_len == 0 || \valid_read(arr + (0 .. arr_len - 1));
    assigns \nothing;
    ensures \result >= 0;
*/
int findOddPair(int * arr, int arr_len, int n) {

		int result = 0;
		int offset = arr_len;
		/*@
		    loop invariant 0 <= c <= offset;
		    loop invariant result >= 0;
		    loop assigns c, result, index;
		    loop variant offset - c;
		*/
		for (int c = 0; c < offset; c++) {
			/*@
			    loop invariant c + 1 <= index <= offset;
			    loop invariant result >= 0;
			    loop assigns index, result;
			    loop variant offset - index;
			*/
			for (int index = c + 1; index < offset; index++) {
				if ((arr[c] ^ arr[index]) % 2 == 1) {
					result++;
				}
			}
		}
		return result;
}
