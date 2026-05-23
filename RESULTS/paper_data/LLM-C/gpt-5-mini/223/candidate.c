/*@
    requires arr_len >= 0;
    requires arr_len == 0 || \valid(arr + (0 .. arr_len-1));
    assigns \nothing;
    ensures \result >= 0;
    ensures \result == \sum integer i; 0 <= i < arr_len;
                        \sum integer j; i+1 <= j < arr_len;
                          (((arr[i] ^ arr[j]) & 1) == 1 ? 1 : 0);
*/
int findOddPair(int * arr, int arr_len, int n);

int findOddPair(int * arr, int arr_len, int n) {

		int result = 0;
		int offset = arr_len;
		/*@
		    loop invariant 0 <= c <= offset;
		    loop invariant result == \sum integer i; 0 <= i < c;
		                              \sum integer j; i+1 <= j < offset;
		                                (((arr[i] ^ arr[j]) & 1) == 1 ? 1 : 0);
		    loop assigns c, result;
		    loop variant offset - c;
		*/
		for (int c = 0; c < offset; c++) {
			/*@
			    loop invariant c+1 <= index <= offset;
			    loop invariant result == \sum integer i; 0 <= i < c;
			                                  \sum integer j; i+1 <= j < offset;
			                                    (((arr[i] ^ arr[j]) & 1) == 1 ? 1 : 0)
			                  + \sum integer j; c+1 <= j < index;
			                      (((arr[c] ^ arr[j]) & 1) == 1 ? 1 : 0);
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
