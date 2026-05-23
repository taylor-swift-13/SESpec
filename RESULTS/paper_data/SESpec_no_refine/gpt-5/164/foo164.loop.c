
/*@
  predicate is_even(int x) = (x & 1) == 0;
*/

/*@
  logic integer pair_count_prefix(int* a, integer n, integer i) =
    i <= 0 ? 0
           : pair_count_prefix(a, n, i - 1)
             + (\sum integer j; i <= j < n; (((a[i - 1] ^ a[j]) & 1) == 0 ? 1 : 0));
*/
        
/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
*/

int foo164(int * arr, int arr_len, int n) {

		if (arr == NULL) {
			return -1;
		}
		if (arr_len == 1) {
			return 0;
		}

		int evenPairCount = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= 0;
          loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre);
          loop assigns \nothing;
            */
            for (int i = 0; i < arr_len; i++) {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant 0 <= i <= arr_len;
              loop invariant 0 <= evenPairCount;
              loop invariant evenPairCount == pair_count_prefix(arr, arr_len, i);
              loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre);
              loop assigns i, evenPairCount;
            */
            for (int c = i + 1; c < arr_len; c++) {
				int even = arr[i];
				int odd = arr[c];
				int z = even ^ odd;
				if ((z & 1) == 0) {
					evenPairCount++;
				}
			}
            
		}
            
		return evenPairCount;
}
