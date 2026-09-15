/*@
    requires arr_len >= 0;
    requires arr_len == 0 || \valid_read(arr + (0 .. arr_len - 1));
    assigns \nothing;
    ensures \result >= 0;
    ensures \result <= (arr_len * (arr_len - 1)) / 2;
*/
int findOddPair(int * arr, int arr_len, int n);

 /*@
    requires arr_len >= 0;
    requires arr_len == 0 || \valid_read(arr + (0 .. arr_len - 1));
    assigns \nothing;
    ensures \result >= 0;
    ensures \result <= (arr_len * (arr_len - 1)) / 2;
*/
int findOddPair(int * arr, int arr_len, int n) {

		int found = 0;
		int offset = arr_len;
		/*@
		    loop invariant 0 <= c <= offset;
		    loop invariant found >= 0;
		    loop invariant found <= (offset * (offset - 1)) / 2;
		    loop assigns c, found, index;
		    loop variant offset - c;
		*/
		for (int c = 0; c < offset; c++) {
			/*@
			    loop invariant c + 1 <= index <= offset;
			    loop invariant found >= 0;
			    loop invariant found <= (offset * (offset - 1)) / 2;
			    loop assigns index, found;
			    loop variant offset - index;
			*/
			for (int index = c + 1; index < offset; index++) {
				if ((arr[c] ^ arr[index]) % 2 == 1) {
					found++;
				}
			}
		}
		return found;
}
