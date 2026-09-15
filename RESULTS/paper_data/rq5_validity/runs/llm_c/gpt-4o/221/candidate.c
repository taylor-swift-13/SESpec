/*@
    requires \valid(arr + (0..arr_len-1));
    requires arr_len >= 0;
    ensures \result >= 0;
    assigns \nothing;
*/
int findOddPair(int * arr, int arr_len, int n);

int findOddPair(int * arr, int arr_len, int n) {

		int found = 0;
		int offset = arr_len;
		/*@
		    loop invariant 0 <= c <= offset;
		    loop invariant found >= 0;
		    loop assigns c, found;
		    loop variant offset - c;
		*/
		for (int c = 0; c < offset; c++) {
			/*@
			    loop invariant c + 1 <= index <= offset;
			    loop invariant found >= 0;
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
