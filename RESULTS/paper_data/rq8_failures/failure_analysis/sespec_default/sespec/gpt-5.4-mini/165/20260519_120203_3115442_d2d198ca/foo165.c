
        /*@
        */
        
/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
  assigns \nothing;
  ensures arr == \null ==> \result == -1;
  ensures arr != \null && arr_len == 1 ==> \result == 0;
  ensures arr != \null && arr_len > 1 ==> \result >= 0;
  ensures arr != \null && arr_len > 1 ==> \result == \sum(0, arr_len - 1, 0, arr_len - 1);
*/
int foo165(int * arr, int arr_len, int n) {

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
          loop assigns i, c, pair, odd, even, evenPairCount;
        */
        
            /*@
          loop invariant (!(i < arr_len)) ==> ();
          loop invariant PLACE_HOLDER_UNCHANGED_ARRAY_arr ;
          loop assigns i, c, pair, odd, even, evenPairCount;
            */
            for (int i = 0; i < arr_len; i++) {
			
        /*@
          loop invariant 0 <= i <= arr_len;
          loop invariant 0 <= evenPairCount;
          loop assigns i, evenPairCount;
          loop variant arr_len - i;
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
