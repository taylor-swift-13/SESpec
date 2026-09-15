
        /*@
        PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
        */
        
/*@
  requires arr == \null || arr_len <= 0 || \valid_read(arr + (0 .. arr_len-1));
  assigns \nothing;
  ensures arr == \null ==> \result == -1;
  ensures arr != \null && arr_len == 1 ==> \result == 0;
  ensures arr != \null && arr_len > 1 ==> \result == foo165_pair_count(arr, arr_len, 0);
  ensures arr != \null ==> \result >= 0;
  ensures \result == -1 || \result == 0 || \result == foo165_pair_count(arr, arr_len, 0);
*/

int foo165(int * arr, int arr_len, int n) {

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
          loop invariant 0 <= evenPairCount;
            */
            for (int i = 0; i < arr_len; i++) {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= i < arr_len;
          loop invariant i + 1 <= c <= arr_len;
          loop invariant 0 <= evenPairCount;
          loop assigns evenPairCount, c;
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
