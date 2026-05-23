
/*@
  logic integer cnt_even_xor_pairs_prefix(int* a, integer n) =
    n <= 1 ? 0
           : cnt_even_xor_pairs_prefix(a, n - 1)
             + (\sum integer j; 0 <= j < n - 1 && (((a[n - 1] ^ a[j]) & 1) == 0) ? 1 : 0);
*/
        
/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
*/

int foo165(int * arr, int arr_len, int n) {

		if (arr == NULL) {
			return -1;
		}
		if (arr_len == 1) {
			return 0;
		}

		int evenPairCount = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= i <= arr_len;
          loop invariant \valid(arr + (0 .. arr_len-1));
          loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre);
          loop invariant 0 <= evenPairCount;
          loop invariant evenPairCount == cnt_even_xor_pairs_prefix(arr, i);
          loop assigns i, c, pair, odd, even, evenPairCount;
            */
            for (int i = 0; i < arr_len; i++) {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= i <= arr_len;
          loop invariant \valid(arr + (0 .. arr_len-1));
          loop invariant 0 <= evenPairCount;
          loop assigns i, evenPairCount;
            */
            for (int c = i + 1; c < arr_len; c++) {
				int pair = arr[i];
				int odd = arr[c];
				int even = pair ^ odd;
				if ((even & 1) == 0) {
					evenPairCount++;
				}
			}
            
		}
            
		return evenPairCount;
}
