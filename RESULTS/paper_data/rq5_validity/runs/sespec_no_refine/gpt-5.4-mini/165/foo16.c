
/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
  assigns \nothing;
  ensures arr == \null ==> \result == -1;
  ensures arr != \null && arr_len == 1 ==> \result == 0;
  ensures arr != \null && arr_len > 1 ==> \result >= 0;
  ensures arr != \null && arr_len > 1 ==> \result <= arr_len * (arr_len - 1) / 2;
*/
int foo16(int * arr, int arr_len, int n) {

		if (arr == NULL) {
			return -1;
		}
		if (arr_len == 1) {
			return 0;
		}

		int evenPairCount = 0;
		
            /*@
          loop invariant 0 <= i <= arr_len;
          loop invariant 0 <= evenPairCount;
          loop invariant evenPairCount <= i * arr_len;
          loop assigns i, c, pair, odd, even, evenPairCount;
            */
        
            /*@
          loop invariant 0 <= i <= arr_len;
          loop invariant 0 <= c <= arr_len;
          loop invariant i + 1 <= c <= arr_len;
          loop invariant 0 <= evenPairCount;
          loop invariant evenPairCount <= arr_len * arr_len;
          loop assigns c, pair, odd, even, evenPairCount;
            */
            for (int i = 0; i < arr_len; i++) {
			
            /*@
              loop invariant 0 <= i <= arr_len;
              loop invariant 0 <= evenPairCount;
              loop invariant evenPairCount <= i * arr_len;
              loop assigns i, evenPairCount;
            */
        
            /*@
          loop invariant i + 1 <= c <= arr_len;
          loop invariant 0 <= evenPairCount;
          loop invariant evenPairCount <= (i + 1) * arr_len;
          loop assigns c, pair, odd, even, evenPairCount;
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
