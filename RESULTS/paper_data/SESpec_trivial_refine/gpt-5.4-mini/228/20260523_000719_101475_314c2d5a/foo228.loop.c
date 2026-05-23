
/*@
logic integer prefix_sum{L}(int *a, integer l, integer u) =
  (l >= u ? 0 : a[l] + prefix_sum{L}(a, l + 1, u));
*/

/*@
  requires 0 <= seed;
  requires seed <= INT_MAX - 1;
*/

int foo228(int seed) {

		int result = 0;
		int *temp = (int *)malloc(sizeof(int) * (seed + 1));
int temp_len = seed + 1;
		temp[0] = 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant \true;
          loop invariant 1 <= d <= seed + 1;
          loop invariant temp[0] == 1;
          loop assigns d, c, temp[d];
            */
            for (int d = 1; d <= seed; d++) {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant \true;
          loop invariant 0 <= c <= d;
          loop invariant d <= seed;
          loop assigns c, temp[d];
            */
            for (int c = 0; c < d; c++) {
				temp[d] = temp[d] + temp[c];
			}
            
		}
            
		return temp[seed];
}
