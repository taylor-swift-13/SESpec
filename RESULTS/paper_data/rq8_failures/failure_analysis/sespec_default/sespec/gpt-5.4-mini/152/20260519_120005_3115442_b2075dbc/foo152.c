
/*@
  logic integer count_odd_upto(integer n) =
    n <= 0 ? 0 : count_odd_upto(n - 1) + (((n - 1) % 2 != 0) ? 1 : 0);
*/

/*@
  logic integer count_even_upto(integer n) =
    n <= 0 ? 0 : count_even_upto(n - 1) + (((n - 1) % 2 == 0) ? 1 : 0);
*/

/*@
  requires number >= 0;
  requires p >= 0;

  assigns \nothing;
*/
int foo152(int number, int p) {

		int *result = (int *)malloc(sizeof(int) * (number));
int result_len = number;
		int *b = (int *)malloc(sizeof(int) * (number));
int b_len = number;
		int c, j = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (c < number) ==> (j <= c);
          loop invariant 0 <= c;
          loop invariant \forall integer k; 0 <= k < c ==> result[k] == k + 1;
          loop assigns c, result[0..number-1];
            */
            for (c = 0; c < number; c++) {
			result[c] = c + 1;
		}
            
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= c;
          loop assigns c, b[0..number-1], j;
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
          loop assigns c, b[0..number-1], j;
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
