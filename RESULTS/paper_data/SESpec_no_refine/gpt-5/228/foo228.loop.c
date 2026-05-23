
/*@
*/

int foo228(int seed) {

		int result = 0;
		int *temp = (int *)malloc(sizeof(int) * (seed + 1));
int temp_len = seed + 1;
		temp[0] = 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= d <= seed + 1;
          loop invariant temp[0] == 1;
          loop invariant \forall integer k; 1 <= k < d ==> temp[k] == k;
          loop invariant \forall integer k; d <= k <= seed ==> temp[k] == 0;
          loop assigns d, c, temp[..];
            */
            for (int d = 1; d <= seed; d++) {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= c <= d;
          loop invariant \forall integer k; 0 <= k < d ==> temp[k] == (k == 0 ? 1 : k);
          loop invariant temp[d] == c;
          loop assigns temp[d], c;
            */
            for (int c = 0; c < d; c++) {
				temp[d] = temp[d] + temp[c];
			}
            
		}
            
		return temp[seed];
}
