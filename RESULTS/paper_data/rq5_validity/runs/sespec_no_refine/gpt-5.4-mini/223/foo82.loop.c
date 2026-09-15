
/*@
  logic integer parity_odd_pairs(int *arr, integer n, integer c) =
    c >= n ? 0 :
    parity_odd_pairs(arr, n, c + 1) +
    (\sum integer j; c + 1 <= j < n; (((arr[c] ^ arr[j]) % 2) == 1 ? 1 : 0));
*/
        
/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
*/

int foo82(int * arr, int arr_len, int n) {

		int result = 0;
		int offset = arr_len;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant c >= 0;
          loop invariant c <= \at(arr_len,Pre);
          loop invariant offset == \at(arr_len,Pre);
          loop invariant n == \at(n,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant 0 <= result <= \at(arr_len,Pre) * (\at(arr_len,Pre) - 1) / 2;
          loop invariant result == parity_odd_pairs(arr, offset, c);
          loop assigns c, index, result;
            */
            for (int c = 0; c < offset; c++) {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant 0 <= c <= offset;
              loop invariant 0 <= result <= offset * (offset - 1) / 2;
              loop assigns c, result;
            */
            for (int index = c + 1; index < offset; index++) {
				if ((arr[c] ^ arr[index]) % 2 == 1) {
					result++;
				}
			}
            
		}
            
		return result;
}
