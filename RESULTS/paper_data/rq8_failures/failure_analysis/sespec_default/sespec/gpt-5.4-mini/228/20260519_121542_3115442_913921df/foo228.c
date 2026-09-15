
/*@
  assigns \nothing;
*/
int foo228(int seed) {

		int result = 0;
		int *temp = (int *)malloc(sizeof(int) * (seed + 1));
int temp_len = seed + 1;
		temp[0] = 1;
		for (int d = 1; d <= seed; d++) {
			
            /* >>> LOOP INVARIANT TO FILL <<< */
            /*@ 
              loop invariant d <= seed + 1;
              loop assigns d, temp[0..seed];
            */
            for (int c = 0; c < d; c++) {
				temp[d] = temp[d] + temp[c];
			}
            
		}
		return temp[seed];
}
