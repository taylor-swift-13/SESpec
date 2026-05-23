
/*@
predicate valid_arr(int *a, integer len) = \valid(a + (0 .. len-1));
*/

/*@
  logic integer even_pairs_count(int *a, integer lo, integer hi) =
    lo >= hi ? 0
             : even_pairs_count(a, lo, hi - 1) +
               (\num_of integer k; lo <= k < hi - 1 && (((a[hi-1] ^ a[k]) & 1) == 0) ? 1 : 0);
*/

        
/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
  assigns \nothing;
  ensures \result == even_pairs_count(arr, 0, arr_len);
*/
int foo14(int * arr, int arr_len, int n) {

		if (arr == NULL) {
			return -1;
		}
		if (arr_len == 1) {
			return 0;
		}

		int evenPairCount = 0;
		
            
        /*@
          loop invariant 0 <= i <= arr_len;
          loop invariant valid_arr(arr, arr_len);
          loop invariant 0 <= evenPairCount <= even_pairs_count(arr, 0, i);
          loop invariant evenPairCount == even_pairs_count(arr, 0, i);
          loop invariant \forall integer k; 0 <= k < arr_len ==> 0 <= arr[k] <= 100;
          loop assigns i, c, odd, b, even, evenPairCount;
        */
            for (int i = 0; i < arr_len; i++) {
			
            
        /*@
            loop invariant 0 <= c <= arr_len;
            loop invariant valid_arr(arr, arr_len);
            loop invariant 0 <= evenPairCount;
            loop invariant evenPairCount == even_pairs_count(arr, 0, i) + even_pairs_count(arr, i, c);
            loop invariant \forall integer k; 0 <= k < arr_len ==> 0 <= arr[k] <= 100;
            loop assigns c, odd, b, even, evenPairCount;
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
