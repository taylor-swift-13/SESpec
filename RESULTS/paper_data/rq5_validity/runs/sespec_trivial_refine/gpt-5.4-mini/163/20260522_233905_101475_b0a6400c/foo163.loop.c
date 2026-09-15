
/*@ logic boolean even_xor(int a, int b) = (((a ^ b) & 1) == 0); */
        
/*@
  requires arr_len >= 0;
  requires arr == \null || arr_len <= 1 || \valid_read(arr + (0 .. arr_len - 1));
*/

int foo163(int * arr, int arr_len, int n) {

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
          loop assigns i, evenPairCount, c, odd, b, even;
            */
            for (int i = 0; i < arr_len; i++) {
			
            /*@
          loop invariant 0 <= i <= arr_len;
          loop invariant 0 <= evenPairCount;
          loop invariant i + 1 <= c <= arr_len;
          loop assigns c, evenPairCount, odd, b, even;
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
