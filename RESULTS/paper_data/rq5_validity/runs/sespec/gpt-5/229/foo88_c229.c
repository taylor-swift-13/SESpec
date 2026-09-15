
/*@
  assigns \nothing;
  ensures \true;
*/
int foo88_c229(int seed) {

		int result = 0;
		int *arr = (int *)malloc(sizeof(int) * (seed + 1));
int arr_len = seed + 1;
		arr[0] = 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant \true;
          loop assigns d, arr[0..arr_len-1];
            */
            for (int d = 1; d <= seed; d++) {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= c;
          loop invariant d > 0 ==> c <= d;
          loop invariant \forall integer k; 0 <= k < c ==> \true;
          loop invariant \forall integer k; c <= k < d ==> \true;
          loop assigns d, arr[0..arr_len-1];
            */
            for (int c = 0; c < d; c++) {
				arr[d] = arr[d] + arr[c];
			}
            
		}
            
		return arr[seed];
}
