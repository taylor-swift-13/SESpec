
#include <stdlib.h>

/*@
  logic integer init_val(integer k) = k + 1;
*/
/*@
        predicate arrays_equal_prefix{L}(int *a, int *b, integer c) =
          \forall integer k; 0 <= k < c ==> a[k] == b[k];
        */

        /*@
        logic integer count_even_prefix(int* a, integer hi) =
          hi <= 0 ? 0 : count_even_prefix(a, hi - 1) + ((a[hi - 1] % 2 == 0) ? 1 : 0);
        */
        

/*@
  predicate initialized_prefix(int *result, integer c) =
    \forall integer k; 0 <= k < c ==> result[k] == init_val(k);
*/



int foo152(int number, int p) {

		int *result = (int *)malloc(sizeof(int) * (number));
int result_len = number;
		int *b = (int *)malloc(sizeof(int) * (number));
int b_len = number;
		int c, j = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= c <= number;
          loop invariant initialized_prefix(result, c);
          loop assigns c, result[..];
            */
            for (c = 0; c < number; c++) {
			result[c] = c + 1;
		}
            
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= c <= number;
          loop invariant arrays_equal_prefix(b, result, c);
          loop invariant \forall integer k; 0 <= k < number ==> result[k] == init_val(k);
          loop invariant 0 <= j <= c;
          loop invariant j == (\sum integer k; 0 <= k < c ? (result[k] % 2 != 0 ? 1 : 0) : 0);
          loop assigns c, b[..], j;
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
          loop invariant 0 <= c <= number;
          loop invariant arrays_equal_prefix(b, result, c);
          loop invariant \forall integer k; 0 <= k < number ==> result[k] == init_val(k);
          loop invariant 0 <= j <= c;
          loop invariant j == count_even_prefix(result, c);
          loop assigns c, b[..], j;
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
