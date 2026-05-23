
/*@
  logic integer cntxorodd_pairs(int* a, integer i, integer lo, integer hi) =
    (hi <= lo) ? 0
               : cntxorodd_pairs(a, i, lo, hi - 1)
                 + (((a[i] ^ a[hi - 1]) % 2 == 1) ? 1 : 0);

  logic integer cntxorodd_prefix(int* a, integer n) =
    (n <= 1) ? 0
             : cntxorodd_prefix(a, n - 1) + cntxorodd_pairs(a, n - 1, 0, n - 1);
*/
        
/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
*/

int foo223(int * arr, int arr_len, int n) {

		int result = 0;
		int offset = arr_len;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= c <= offset;
          loop invariant offset == arr_len;
          loop invariant n == \at(n,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k],Pre);
          loop invariant result == cntxorodd_prefix(arr, c);
          loop assigns c, index, result;
            */
            for (int c = 0; c < offset; c++) {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant c + 1 <= index <= offset;
          loop invariant result >= 0;
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
