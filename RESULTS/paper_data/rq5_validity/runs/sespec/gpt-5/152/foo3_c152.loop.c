
#include <stdlib.h>

/*@
  logic integer cntodd(int* a, integer lo, integer hi) =
    lo >= hi ? 0
             : cntodd(a, lo, hi - 1) + (a[hi - 1] % 2 != 0 ? 1 : 0);
*/

/*@
  logic integer cnteven(int* a, integer lo, integer hi) =
    lo >= hi ? 0
             : cnteven(a, lo, hi - 1) + (a[hi - 1] % 2 == 0 ? 1 : 0);
*/

int foo3_c152(int number, int p) {

		int *result = (int *)malloc(sizeof(int) * (number));
int result_len = number;
		int *b = (int *)malloc(sizeof(int) * (number));
int b_len = number;
		int c, j = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= c;
          loop invariant \forall integer k; 0 <= k < c ==> result[k] == k + 1;
          loop assigns c, result[0 .. result_len-1];
            */
            for (c = 0; c < number; c++) {
			result[c] = c + 1;
		}
            
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= c;
          loop invariant 0 <= j <= c;
          loop assigns c, b[0 .. b_len-1], j;
            */
            for (c = 0; c < number; c++) {
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
          loop invariant 0 <= c;
          loop invariant 0 <= j;
          loop invariant \forall integer k; 0 <= k < result_len ==> result[k] == result[k];
          loop assigns c, b[0 .. b_len-1], j;
            */
            for (c = 0; c < number; c++) {
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
