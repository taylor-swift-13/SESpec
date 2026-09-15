/*@
    requires \valid(arr+(0..arr_len-1));
    requires arr_len >= 0;
    ensures \result >= 0;
    assigns \nothing;
*/
int findOddPair(int * arr, int arr_len, int n);

int findOddPair(int * arr, int arr_len, int n) {

		int result = 0;
		int offset = arr_len;
		/*@
		    loop invariant 0 <= index <= offset;
		    loop invariant result >= 0;
		    loop assigns index, result;
		    loop variant offset - index;
		*/
		for (int index = 0; index < offset; index++) {
			/*@
			    loop invariant index + 1 <= c <= offset;
			    loop invariant result >= 0;
			    loop assigns c, result;
			    loop variant offset - c;
			*/
			for (int c = index + 1; c < offset; c++) {
				if ((arr[index] ^ arr[c]) % 2 == 1) {
					result++;
				}
			}
		}
		return result;
}
