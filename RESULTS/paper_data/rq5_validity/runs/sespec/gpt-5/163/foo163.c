
/*@
  predicate is_even(int x) = (x & 1) == 0;
*/

/*@
  logic integer cnt_even_pairs_prefix(int* a, integer n, integer hi) =
    hi <= 1 ? 0
            : cnt_even_pairs_prefix(a, n, hi - 1)
              + ( \sum integer p; 0 <= p < hi - 1 :
                    ( ((a[p] ^ a[hi - 1]) & 1) == 0 ? 1 : 0 ) );
*/
        
/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  assigns \nothing;
  ensures \forall integer k; 0 <= k < arr_len ==> arr[k] == \old(arr[k]);
  ensures arr == \null ==> \result == -1;
  ensures arr != \null && arr_len == 1 ==> \result == 0;
  ensures arr != \null && arr_len <= 1 ==> \result == 0;
  ensures arr != \null && arr_len >= 0 ==> \result >= 0;
  ensures arr != \null && arr_len >= 2 ==> \result == cnt_even_pairs_prefix(arr, arr_len, arr_len);
  ensures arr != \null ==> \result <= (arr_len * (arr_len - 1)) / 2;
  ensures \result == PLACE_HOLDER_RESULT;
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
          loop invariant 0 <= evenPairCount <= (arr_len * (arr_len - 1)) / 2;
          loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre);
          loop invariant \forall integer k; 0 <= k < arr_len ==> 0 <= arr[k] <= 100;
          loop invariant evenPairCount == cnt_even_pairs_prefix(arr, arr_len, i);
          loop invariant (i == 0) ==> (evenPairCount == 0);
          loop invariant (i < arr_len) ==> (evenPairCount <= cnt_even_pairs_prefix(arr, arr_len, i + 1));
          loop invariant (i == arr_len) ==> (evenPairCount == cnt_even_pairs_prefix(arr, arr_len, arr_len));
          loop assigns i, c, odd, b, even, evenPairCount;
            */
            for (int i = 0; i < arr_len; i++) {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= i <= arr_len;
          loop invariant evenPairCount >= 0;
          loop assigns evenPairCount, i;
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
