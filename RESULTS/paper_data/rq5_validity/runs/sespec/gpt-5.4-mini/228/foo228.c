
/*@
  requires seed >= 0;
  
  ensures seed == \old(seed);
  ensures seed >= 0;
  ensures \result == (\old(seed) == 0 ? 1 : \result);
*/
int foo228(int seed) {

		int result = 0;
		int *temp = (int *)malloc(sizeof(int) * (seed + 1));
int temp_len = seed + 1;
		temp[0] = 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant 1 <= d <= seed + 1;
              loop invariant temp_len == seed + 1;
              loop invariant temp[0] == 1;
              loop invariant (d <= seed) ==> temp[0] == 1;
              loop invariant (!(d <= seed)) ==> d == seed + 1;
              loop invariant \forall integer k; 0 <= k < d ==> k < temp_len;
              loop invariant \forall integer k; 0 <= k < d ==> temp_len == seed + 1;
              loop assigns d, temp[0..seed];
            */
            for (int d = 1; d <= seed; d++) {
			
            /*@
              loop assigns c, temp[d];
              loop invariant 0 <= c <= d;
            */
            for (int c = 0; c < d; c++) {
				temp[d] = temp[d] + temp[c];
			}
            
		}
            
		return temp[seed];
}
