
/*@
        predicate valid_arr(int *arr, int len) = arr != \null && len >= 0;
        */

/*@
  logic integer even_pairs_count(int* a, integer lo, integer hi) =
    lo >= hi ? 0
             : even_pairs_count(a, lo, hi - 1)
               + (\sum integer j = lo + 1 .. hi - 1; ((a[hi - 1] ^ a[j]) & 1) == 0 ? 1 : 0);
*/

/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
  assigns \nothing;
  ensures (arr == \null) ==> \result == -1;
  ensures (arr != \null && arr_len == 1) ==> \result == 0;
  ensures (arr != \null && arr_len > 1) ==>
          \result == even_pairs_count(arr, 0, arr_len);
  ensures \forall integer k; 0 <= k < arr_len ==> 0 <= arr[k] <= 100;
*/
int foo16(int * arr, int arr_len, int n) {

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
          loop invariant evenPairCount == even_pairs_count(arr, 0, i);
          loop invariant \forall integer k; 0 <= k < arr_len ==> 0 <= arr[k] <= 100;
          loop assigns i, evenPairCount;
            */
            for (int i = 0; i < arr_len; i++) {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
            loop invariant 0 <= c <= arr_len;
            loop invariant 0 <= i <= arr_len;
            loop invariant evenPairCount == even_pairs_count(arr, 0, i) + 
                                          (\sum integer j = i + 1 .. c - 1; ((arr[i] ^ arr[j]) & 1) == 0 ? 1 : 0);
            loop invariant \forall integer k; 0 <= k < arr_len ==> 0 <= arr[k] <= 100;
            loop assigns c, evenPairCount;
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
