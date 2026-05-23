
        /*@
        PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
        */
        
/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
  assigns \nothing;
  ensures arr == \null ==> \result == -1;
  ensures arr != \null && arr_len == 1 ==> \result == 0;
  ensures arr != \null && arr_len > 1 ==> 0 <= \result <= arr_len * (arr_len - 1) / 2;
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
            loop invariant 0 <= evenPairCount <= arr_len * (arr_len - 1) / 2;
            loop assigns i, c, even, odd, z, evenPairCount;
            */
            /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (!(i < arr_len)) ==> ();
          loop invariant PLACE_HOLDER_UNCHANGED_ARRAY_arr ;
          loop assigns i, c, even, odd, z, evenPairCount;
            */
            for (int i = 0; i < arr_len; i++) {
			
            /*@
            loop invariant 0 <= i <= arr_len;
            loop invariant 0 <= evenPairCount <= arr_len * (arr_len - 1) / 2;
            loop assigns i, evenPairCount;
            */
            /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
            loop invariant i + 1 <= c <= arr_len;
            loop assigns c, evenPairCount;
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
