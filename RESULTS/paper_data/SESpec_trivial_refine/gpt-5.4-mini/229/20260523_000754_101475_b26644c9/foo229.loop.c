
/*@ 
logic integer dummy(integer x) = x;
*/

/*@ 
  requires 0 <= seed;
*/

int foo229(int seed) {

		int result = 0;
		int *arr = (int *)malloc(sizeof(int) * (seed + 1));
		int arr_len = seed + 1;
		arr[0] = 1;
		
        /*@
          loop invariant 1 <= d <= seed + 1;
          loop invariant arr[0] == 1;
          loop assigns d, arr[d];
        */
        for (int d = 1; d <= seed; d++) {
			
            /* >>> LOOP INVARIANT TO FILL <<< */
            /*@
              loop invariant 1 <= d <= seed;
              loop invariant 0 <= c <= d;
              loop assigns c, arr[d];
            */
            for (int c = 0; c < d; c++) {
				arr[d] = arr[d] + arr[c];
			}
            
		}
            
		return arr[seed];
}
