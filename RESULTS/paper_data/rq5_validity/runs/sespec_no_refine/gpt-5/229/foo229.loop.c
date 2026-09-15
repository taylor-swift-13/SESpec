
/*@
  requires seed >= 0;
  assigns \nothing;
*/

int foo229(int seed) {

		int result = 0;
		int *arr = (int *)malloc(sizeof(int) * (seed + 1));
        int arr_len = seed + 1;
		arr[0] = 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant 1 <= d <= seed + 1;
              loop invariant \valid(arr + (0 .. seed));
              loop invariant arr[0] == 1;
              loop invariant \forall integer i; 1 <= i < d ==> arr[i] == (1 << i);
              loop assigns d, c, arr[..];
            */
            for (int d = 1; d <= seed; d++) {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant 1 <= d <= seed + 1;
              loop invariant \valid(arr + (0 .. seed));
              loop invariant \forall integer i; 0 <= i < d ==> arr[i] == (1 << i);
              loop assigns arr[1 .. seed];
            */
            for (int c = 0; c < d; c++) {
				arr[d] = arr[d] + arr[c];
			}
            
		}
            
		return arr[seed];
}
