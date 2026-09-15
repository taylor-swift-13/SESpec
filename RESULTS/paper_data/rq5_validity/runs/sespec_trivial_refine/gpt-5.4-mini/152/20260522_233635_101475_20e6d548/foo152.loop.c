
/*@
predicate odd(integer x) = x % 2 != 0;
*/

/*@
  requires 0 <= number;
*/


int foo152(int number, int p) {

		int *result = (int *)malloc(sizeof(int) * (number));
int result_len = number;
		int *b = (int *)malloc(sizeof(int) * (number));
int b_len = number;
		int c, j = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant c == 0 || 0 <= c <= number;
          loop invariant \forall integer i; 0 <= i < c ==> result[i] == i + 1;
          loop assigns c, result[0 .. number-1];
            */
            for (c = 0; c < number; c++) {
			result[c] = c + 1;
		}
            
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= c <= number;
          loop invariant \forall integer i; 0 <= i < c ==> b[i] == result[i];
          loop invariant j == \numof integer k; 0 <= k < c && result[k] % 2 != 0;
          loop assigns c, j, b[0 .. number-1];
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
          loop invariant 0 <= j <= number;
          loop invariant 0 <= c <= number;
          loop invariant \forall integer i; 0 <= i < c ==> b[i] == result[i];
          loop assigns c, j, b[0 .. number-1];
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
