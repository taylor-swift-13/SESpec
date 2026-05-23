int findOddPair(int * arr, int arr_len, int n);

/*@
    requires arr != \null;
    requires arr_len >= 0;
    requires arr_len == 0 || \valid(arr + (0 .. arr_len-1));
    assigns \nothing;
    ensures \result >= 0;
    ensures \result ==
        (\sum integer i; 0 <= i < arr_len;
            (\sum integer j; i+1 <= j < arr_len;
                ((arr[i] ^ arr[j]) % 2 == 1) ? 1 : 0));
*/
int findOddPair(int * arr, int arr_len, int n) {

		int result = 0;
		int offset = arr_len;
		/*@
		    loop invariant 0 <= index <= offset;
		    loop invariant 0 <= offset;
		    loop invariant offset == arr_len;
		    loop invariant result ==
		        (\sum integer ii; 0 <= ii < index;
		            (\sum integer jj; ii+1 <= jj < offset;
		                ((arr[ii] ^ arr[jj]) % 2 == 1) ? 1 : 0));
		    loop assigns index, result;
		    loop variant offset - index;
		*/
		for (int index = 0; index < offset; index++) {
			/*@
			    loop invariant index+1 <= c <= offset;
			    loop invariant result ==
			        (\sum integer ii; 0 <= ii < index;
			            (\sum integer jj; ii+1 <= jj < offset;
			                ((arr[ii] ^ arr[jj]) % 2 == 1) ? 1 : 0))
			        +
			        (\sum integer jj; index+1 <= jj < c;
			            ((arr[index] ^ arr[jj]) % 2 == 1) ? 1 : 0);
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
