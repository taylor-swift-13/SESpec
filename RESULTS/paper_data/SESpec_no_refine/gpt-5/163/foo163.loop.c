
/*@
  logic integer pair_even_cnt(int* a, integer n, integer hi) =
    hi <= 0 ? 0
            : pair_even_cnt(a, n, hi - 1)
              + (\sum integer j; hi <= j < n :
                    ((((a[hi-1] ^ a[j]) & 1) == 0) ? 1 : 0));
*/
        
/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
*/

int foo163(int * arr, int arr_len, int n) {

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
          loop invariant \forall integer k; 0 <= k < arr_len ==> 0 <= arr[k] <= 100;
          loop invariant evenPairCount == pair_even_cnt(arr, arr_len, i);
          loop assigns i, evenPairCount, arr[..];
            */
            for (int i = 0; i < arr_len; i++) {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant i + 1 <= c <= arr_len;
          loop invariant \forall integer k; 0 <= k < arr_len ==> 0 <= arr[k] <= 100;
          loop invariant evenPairCount
            == pair_even_cnt(arr, arr_len, i)
               + \sum integer j; i + 1 <= j < c :
                    ((((arr[i] ^ arr[j]) & 1) == 0) ? 1 : 0);
          loop assigns i, c, odd, b, even, evenPairCount;
            */
            for (int c = i + 1; c < arr_len; c++) {
				int odd = arr[i];
				int b = arr[c];
				int even = odd ^ b;
				if ((even & 1) == 0) {
					evenPairCount++;
				}
			}
            
		}
            
		return evenPairCount;
}
