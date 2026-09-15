
/*@
  logic integer cnt_odd_xor_pairs(int* a, integer lo_i, integer hi_i, integer lo_j, integer hi_j) =
    (lo_i >= hi_i || lo_j >= hi_j)
      ? 0
      : ( (lo_i + 1 < lo_j && lo_j < hi_j)
            ? cnt_odd_xor_pairs(a, lo_i, hi_i, lo_j - 1, hi_j)
              + (((a[lo_i] ^ a[lo_j - 1]) % 2 == 1) ? 1 : 0)
            : cnt_odd_xor_pairs(a, lo_i + 1, hi_i, lo_i + 2, hi_j) );
*/
        
/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
*/

int foo221(int * arr, int arr_len, int n) {

		int found = 0;
		int offset = arr_len;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant offset == \at(arr_len,Pre);
          loop invariant n == \at(n,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant \forall integer k; 0 <= k < offset ==> 0 <= arr[k] <= 100;
          loop invariant \forall integer k; 0 <= k < offset ==> arr[k] == \at(arr[k], Pre);
          loop invariant found >= 0;
          loop invariant (c < \at(arr_len,Pre)) ==> (\forall integer k; 0 <= k < offset ==> arr[k] == \at(arr[k], Pre));
            */
            for (int c = 0; c < offset; c++) {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant found >= 0;
          loop assigns c, found;
            */
            for (int index = c + 1; index < offset; index++) {
				if ((arr[c] ^ arr[index]) % 2 == 1) {
					found++;
				}
			}
            
		}
            
		return found;
}
