int findOddPair(int * arr, int arr_len, int n);

/*@ 
  logic integer count_xor_mod2_pairs(int *arr, integer n) =
    \sum(integer i, 0, n-1,
         \sum(integer j, i+1, n-1, (((arr[i] ^ arr[j]) % 2) == 1) ? 1 : 0));

  logic integer count_xor_mod2_pairs_prefix(int *arr, integer n, integer c) =
    \sum(integer i, 0, c-1,
         \sum(integer j, i+1, n-1, (((arr[i] ^ arr[j]) % 2) == 1) ? 1 : 0));

  logic integer count_xor_mod2_pairs_for_c_up_to(int *arr, integer n, integer c, integer idx) =
    \sum(integer j, c+1, idx-1, (((arr[c] ^ arr[j]) % 2) == 1) ? 1 : 0);
*/

/*@
  requires arr_len >= 0;
  requires arr_len == 0 || \valid_read(arr + (0..arr_len-1));
  assigns \nothing;
  ensures \result == count_xor_mod2_pairs(arr, arr_len);
  ensures 0 <= \result;
  ensures \result <= (arr_len * (arr_len - 1)) / 2;
*/
int findOddPair(int * arr, int arr_len, int n) {

		int result = 0;
		int offset = arr_len;
		/*@ 
		  loop invariant 0 <= c <= offset;
		  loop invariant result == count_xor_mod2_pairs_prefix(arr, offset, c);
		  loop assigns result, c;
		  loop variant offset - c;
		*/
		for (int c = 0; c < offset; c++) {
			/*@
			  loop invariant c + 1 <= index <= offset;
			  loop invariant result == count_xor_mod2_pairs_prefix(arr, offset, c)
			                     + count_xor_mod2_pairs_for_c_up_to(arr, offset, c, index);
			  loop assigns result, index;
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
