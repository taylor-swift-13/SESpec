
#include <stdlib.h>

/*@
  logic integer count_odd_upto(integer n) =
    n <= 0 ? 0 : count_odd_upto(n - 1) + (((n - 1) % 2 != 0) ? 1 : 0);

  logic integer count_even_upto(integer n) =
    n <= 0 ? 0 : count_even_upto(n - 1) + (((n - 1) % 2 == 0) ? 1 : 0);
*/

int foo150(int value, int p) {

		int *result = (int *)malloc(sizeof(int) * (value));
int result_len = value;
		int *b = (int *)malloc(sizeof(int) * (value));
int b_len = value;
		int c, j = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= j <= c;
          loop invariant \forall integer k; 0 <= k < c ==> result[k] == k + 1;
          loop assigns c, result[0..value-1];
            */
            for (c = 0; c < value; c++) {
			result[c] = c + 1;
		}
            
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= j <= c;
          loop assigns c, b[0..value-1], j;
            */
            for (c = 0; c < value; c++) {
			b[c] = result[c];
			if (result[c] % 2 != 0) {
				j++;
				if (j == p) {
					return result[c];
				}
			}
		}
            
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop assigns c, b[0..value-1], j;
            */
            for (c = 0; c < value; c++) {
			b[c] = result[c];
			if (result[c] % 2 == 0) {
				j++;
				if (j == p) {
					return result[c];
				}
			}
		}
            
		return 0;
}
