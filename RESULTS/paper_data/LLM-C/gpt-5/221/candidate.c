int findOddPair(int * arr, int arr_len, int n);

/*@ 
  requires arr_len >= 0;
  requires \valid_read(arr + (0 .. arr_len-1));
  // prevent signed overflow of `found`
  requires ((arr_len * (arr_len - 1)) / 2) <= \max_int;

  assigns \nothing;

  ensures \result == \numof integer c, index; 
                     0 <= c < index < arr_len && (((arr[c] ^ arr[index]) % 2) == 1);
  ensures 0 <= \result <= (arr_len * (arr_len - 1)) / 2;
*/
int findOddPair(int * arr, int arr_len, int n) {

		int found = 0;
		int offset = arr_len;
		/*@
		  loop invariant 0 <= c <= offset;
		  loop invariant offset == arr_len;
		  loop invariant found == \numof integer i, j;
		                          0 <= i < c && i < j < offset &&
		                          (((arr[i] ^ arr[j]) % 2) == 1);
		  loop assigns c, found;
		  loop variant offset - c;
		*/
		for (int c = 0; c < offset; c++) {
			/*@
			  loop invariant c + 1 <= index <= offset;
			  loop invariant 0 <= c < offset;
			  loop invariant found == \numof integer i, j;
			                          ((0 <= i < c && i < j < offset) ||
			                           (i == c && c + 1 <= j < index)) &&
			                          (((arr[i] ^ arr[j]) % 2) == 1);
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
