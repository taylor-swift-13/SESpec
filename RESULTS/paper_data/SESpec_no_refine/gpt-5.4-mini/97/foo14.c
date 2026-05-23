
        /*@
        logic integer count_even_pairs(int* arr, integer lo, integer hi) =
          lo >= hi ? 0 :
          count_even_pairs(arr, lo, hi - 1) +
          ( ((arr[lo] ^ arr[hi - 1]) & 1) == 0 ? 1 : 0 );
        */
        
/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
  assigns evenPairCount, i, c, odd, b, even;
  ensures arr == \old(arr);
  ensures arr_len == \old(arr_len);
  ensures n == \old(n);
  ensures arr == \old(arr) && arr_len == \old(arr_len) && n == \old(n);
  ensures \result == -1 || \result == 0 || \result == count_even_pairs(arr, 0, arr_len);
  ensures (arr == \null) ==> \result == -1;
  ensures (arr != \null && arr_len == 1) ==> \result == 0;
  ensures (arr != \null && arr_len > 1) ==> \result == count_even_pairs(arr, 0, arr_len);
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
          loop invariant evenPairCount == count_even_pairs(arr, 0, i);
          loop assigns i, evenPairCount;
          loop variant arr_len - i;
        */
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (!(i < arr_len)) ==> ();
          loop invariant PLACE_HOLDER_UNCHANGED_ARRAY_arr ;
          loop assigns i, c, odd, b, even, evenPairCount;
            */
            for (int i = 0; i < arr_len; i++) {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant i + 1 <= c <= arr_len;
          loop invariant evenPairCount == \numof(int k1, int k2; 0 <= k1 < i && i < k2 < arr_len && (((arr[k1] ^ arr[k2]) & 1) == 0))
                          + \numof(int k1, int k2; 0 <= k1 < i && i < k2 < c && (((arr[k1] ^ arr[k2]) & 1) == 0));
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
