
/*@ 
  logic integer xor_odd_pairs_inner(int* a, integer c, integer j, integer n) =
    j >= n ? 0
           : (((a[c] ^ a[j]) % 2 == 1) ? 1 : 0) + xor_odd_pairs_inner(a, c, j + 1, n);
*/

/*@ 
  logic integer xor_odd_pairs_up_to(int* a, integer n, integer upto) =
    upto <= 0 ? 0
              : xor_odd_pairs_up_to(a, n, upto - 1)
                + ( \let c = upto - 1;
                    xor_odd_pairs_inner(a, c, c + 1, n));
*/
        
/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
*/

int foo82_c223(int * arr, int arr_len, int n) {

		int result = 0;
		int offset = arr_len;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= c <= offset;
          loop invariant offset == arr_len;
          loop invariant n == \at(n,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre);
            */
            for (int c = 0; c < offset; c++) {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= c < offset;
          loop invariant offset == arr_len;
          loop invariant arr == \at(arr,Pre);
          loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre);
          loop invariant c + 1 <= index <= offset;
          loop assigns result, index;
            */
            for (int index = c + 1; index < offset; index++) {
				if ((arr[c] ^ arr[index]) % 2 == 1) {
					result++;
				}
			}
            
		}
            
		return result;
}
