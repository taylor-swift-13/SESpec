
/*@
  requires 0 <= number;
*/

int foo151(int number, int p) {

		int *result = (int *)malloc(sizeof(int) * (number));
int result_len = number;
		int *b = (int *)malloc(sizeof(int) * (number));
int b_len = number;
		int c, ii = 0;
		
            /*@
          loop invariant 0 <= c <= number;
          loop invariant \forall integer k; 0 <= k < c ==> result[k] == k + 1;
          loop assigns c, result[0 .. number - 1];
            */
            for (c = 0; c < number; c++) {
			result[c] = c + 1;
		}
            
		
            
            /*@
          loop invariant 0 <= c <= number;
          loop assigns c, b[0 .. number - 1], ii;
            */
            for (c = 0; c < number; c++) {
			b[c] = result[c];
			if (result[c] % 2 != 0) {
				ii++;
				if (ii == p) {
					return result[c];
				}
			}
		}
            
		
            
            /*@
          loop invariant 0 <= c <= number;
          loop assigns c, b[0 .. number - 1], ii;
            */
            for (c = 0; c < number; c++) {
			b[c] = result[c];
			if (result[c] % 2 == 0) {
				ii++;
				if (ii == p) {
					return result[c];
				}
			}
		}
            
		return 0;
}
