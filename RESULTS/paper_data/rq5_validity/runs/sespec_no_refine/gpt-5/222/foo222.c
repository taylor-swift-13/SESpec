
/*@
  predicate PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION == \true ;
*/

/*@
  logic integer cnt_xor_odd_pairs_prefix(int* a, integer hi) =
    hi <= 0 ? 0
            : cnt_xor_odd_pairs_prefix(a, hi - 1)
              + (\sum integer j; 0 <= j < hi - 1 && (((a[hi - 1] ^ a[j]) % 2) == 1) ? 1 : 0);
*/
        
/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
  assigns \nothing;   
  ensures \result == cnt_xor_odd_pairs_prefix(arr, arr_len); 
  ensures \forall integer k; 0 <= k < arr_len ==> arr[k] == \old(arr[k]);
*/

int foo222(int * arr, int arr_len, int n) {

		int result = 0;
		int offset = arr_len;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant 0 <= index <= offset;
              loop invariant offset == arr_len;
              loop invariant result == cnt_xor_odd_pairs_prefix(arr, index);
              loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre);
              loop assigns index, c, result;
            */
            for (int index = 0; index < offset; index++) {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant index + 1 <= offset <= arr_len;
              loop invariant index >= 0;
              loop invariant \forall integer k; index + 1 <= k < c ==> 0 <= k < offset;
              loop invariant result == cnt_xor_odd_pairs_prefix(arr, index)
                               + (\sum integer j; index + 1 <= j < c && (((arr[index] ^ arr[j]) % 2) == 1) ? 1 : 0);
              loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre);
              loop assigns result, c;
            */
            for (int c = index + 1; c < offset; c++) {
				if ((arr[index] ^ arr[c]) % 2 == 1) {
					result++;
				}
			}
            
		}
            
		return result;
}
