
/*@
  logic integer count_even_pairs(int* arr, integer lo, integer hi) =
    lo >= hi ? 0 :
    count_even_pairs(arr, lo, hi - 1) +
      (((arr[hi - 2] ^ arr[hi - 1]) & 1) == 0 ? 1 : 0);
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
          loop invariant 0 <= evenPairCount <= i * (arr_len - 1);
          loop invariant evenPairCount == count_even_pairs(arr, 0, i);
          loop assigns i, c, even, odd, z, evenPairCount;
            */
            for (int i = 0; i < arr_len; i++) {
			
            /*@
              loop invariant 0 <= i <= arr_len;
              loop invariant 0 <= evenPairCount <= i * (arr_len - 1);
              loop invariant evenPairCount == count_even_pairs(arr, 0, i);
              loop assigns i, evenPairCount;
              loop variant arr_len - i;
            */
            /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant i + 1 <= c <= arr_len;
              loop assigns c, evenPairCount;
              loop variant arr_len - c;
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
