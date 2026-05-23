
/*@ 
  logic integer count_eq_int{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0 : count_eq_int(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/
/*@
  logic integer cnt_odd(int* a, integer lo, integer hi) =
    lo >= hi ? 0 : cnt_odd(a, lo, hi - 1) + (a[hi - 1] % 2 != 0 ? 1 : 0);
*/

/*@
  logic integer cnt_even(int* a, integer lo, integer hi) =
    lo >= hi ? 0 : cnt_even(a, lo, hi - 1) + (a[hi - 1] % 2 == 0 ? 1 : 0);
*/
        

/*@ 
  predicate eq_prefix{L}(int* a, int* b, integer n) =
    \forall integer i; 0 <= i < n ==> a[i] == b[i];
*/



int foo2_c151(int number, int p) {

		int *result = (int *)malloc(sizeof(int) * (number));
int result_len = number;
		int *b = (int *)malloc(sizeof(int) * (number));
int b_len = number;
		int c, ii = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= c;
          loop invariant \forall integer k; 0 <= k < c ==> result[k] == k + 1;
          loop invariant (!(c < number)) ==> (\forall integer k; 0 <= k < number ==> result[k] == k + 1);
          loop assigns c, result[0..number-1];
            */
            for (c = 0; c < number; c++) {
			result[c] = c + 1;
		}
            
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= c;
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
