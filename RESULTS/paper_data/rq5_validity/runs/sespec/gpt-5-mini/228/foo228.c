
/*@
  logic integer sum_prefix(int* a, integer lo, integer hi) =
    lo >= hi ? 0 : sum_prefix(a, lo, hi - 1) + a[hi - 1];
*/
        

/*@
  requires seed >= 0;
*/
int foo228(int seed) {

		int result = 0;
		int *temp = (int *)malloc(sizeof(int) * (seed + 1));
int temp_len = seed + 1;
		temp[0] = 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant \forall integer k; 0 <= k < d ==> temp[k] == temp[k];
            */
            for (int d = 1; d <= seed; d++) {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop assigns d, c, temp[0..seed];
            */
            for (int c = 0; c < d; c++) {
				temp[d] = temp[d] + temp[c];
			}
            
		}
            
		return temp[seed];
}
