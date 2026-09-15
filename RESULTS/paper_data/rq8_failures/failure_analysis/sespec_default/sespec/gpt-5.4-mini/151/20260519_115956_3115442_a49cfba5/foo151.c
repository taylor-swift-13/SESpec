
/*@ logic integer count_odd(int* a, integer lo, integer hi) =
      lo >= hi ? 0 : count_odd(a, lo, hi - 1) + ((a[hi - 1] % 2) != 0 ? 1 : 0);
*/
/*@ logic integer count_even(int* a, integer lo, integer hi) =
      lo >= hi ? 0 : count_even(a, lo, hi - 1) + ((a[hi - 1] % 2) == 0 ? 1 : 0);
*/

#include <stdlib.h>

/*@
  ensures number <= 0 ==> \result == 0;
  ensures number > 0 && p <= 0 ==> \result == 0;
  assigns \nothing;
*/
int foo151(int number, int p) {

		int *result = (int *)malloc(sizeof(int) * (number));
int result_len = number;
		int *b = (int *)malloc(sizeof(int) * (number));
int b_len = number;
		int c, ii = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant result_len == number;
          loop invariant b_len == number;
          loop invariant \forall integer k; 0 <= k < c ==> result[k] == k + 1;
          loop assigns c, result[0..number-1];
            */
            for (c = 0; c < number; c++) {
			result[c] = c + 1;
		}
            
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= ii <= c;
          loop invariant result_len == number;
          loop invariant b_len == number;
          loop assigns c, b[0..number-1], ii;
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
            
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= c;
          loop invariant number < 0 || c <= number;
          loop invariant 0 <= ii;
          loop invariant result_len == number;
          loop invariant b_len == number;
          loop assigns c, b[0..number-1], ii;
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
