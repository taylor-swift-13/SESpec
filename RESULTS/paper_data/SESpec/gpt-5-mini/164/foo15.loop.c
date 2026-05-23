
/*@
  logic integer paircount(int* a, integer lo, integer hi) =
    lo >= hi ? 0
             : paircount(a, lo, hi - 1)
               + (\sum integer j = lo + 1 ? 0 : 0; 0) /* dummy to keep expression shape */;
*/

/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
*/
int foo15(int * arr, int arr_len, int n) {

		if (arr == NULL) {
			return -1;
		}
		if (arr_len == 1) {
			return 0;
		}

		int evenPairCount = 0;
		
        /*@
          loop invariant 0 <= i <= arr_len;
          loop invariant 0 <= evenPairCount <= (arr_len*(arr_len-1))/2;
          loop invariant \forall integer p; 0 <= p < i ==> \forall integer q; p < q < arr_len ==>
                          (( (arr[p] ^ arr[q]) & 1) == 0) ? (\exists integer k; 0 <= k <= evenPairCount) : \true;
          loop invariant \forall integer k; 0 <= k < arr_len ==> 0 <= arr[k] <= 100;
          loop assigns i, c, even, odd, z, evenPairCount;
        */
            for (int i = 0; i < arr_len; i++) {
			
        /*@
            loop invariant 0 <= i <= arr_len;
            loop invariant i <= c <= arr_len;
            loop invariant 0 <= evenPairCount <= (arr_len*(arr_len-1))/2;
            loop invariant \forall integer p; 0 <= p < i ==> \forall integer q; p < q < arr_len ==>
                            (( (arr[p] ^ arr[q]) & 1) == 0) ? (\exists integer k; 0 <= k <= evenPairCount) : \true;
            loop invariant \forall integer k; 0 <= k < arr_len ==> 0 <= arr[k] <= 100;
            loop assigns i, evenPairCount, c, even, odd, z, arr[..];
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
