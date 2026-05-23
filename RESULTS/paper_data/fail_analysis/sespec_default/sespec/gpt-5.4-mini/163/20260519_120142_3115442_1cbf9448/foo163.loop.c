
        /*@
        PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
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
          loop invariant 0 <= evenPairCount <= arr_len * (arr_len - 1) / 2;
          loop assigns i, c, odd, b, even, evenPairCount;
            */
            for (int i = 0; i < arr_len; i++) {
			
            /*@
              loop invariant 0 <= i <= arr_len;
              loop invariant 0 <= evenPairCount <= arr_len * (arr_len - 1) / 2;
              loop assigns i, evenPairCount;
              loop variant arr_len - i;
            */
            /*@
              loop invariant i + 1 <= c <= arr_len;
              loop invariant 0 <= evenPairCount <= arr_len * (arr_len - 1) / 2;
              loop assigns c, evenPairCount;
              loop variant arr_len - c;
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
