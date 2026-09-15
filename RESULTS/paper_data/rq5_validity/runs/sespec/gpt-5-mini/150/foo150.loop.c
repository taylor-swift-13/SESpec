
/*@
  logic integer seq_val(integer i) = i + 1;
*/
/*@
  predicate init_result(int* result, integer len, integer upto) =
    0 <= upto <= len &&
    \forall integer k; 0 <= k < upto ==> result[k] == seq_val(k) &&
    \forall integer k; upto <= k < len ==> \true;
*/
/*@
  predicate prefix_eq(int* a, int* b, integer n, integer upto) =
    0 <= upto <= n &&
    \forall integer k; 0 <= k < upto ==> a[k] == b[k];
*/

/*@
  requires value >= 0;
*/
int foo150(int value, int p) {

		int *result = (int *)malloc(sizeof(int) * (value));
int result_len = value;
		int *b = (int *)malloc(sizeof(int) * (value));
int b_len = value;
		int c, j = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= c <= value;
          loop invariant \forall integer k; 0 <= k < c ==> result[k] == seq_val(k);
          loop invariant (!(c < value)) ==> (\forall integer k; 0 <= k < value ==> result[k] == seq_val(k));
          loop assigns c, result[0 .. value-1];
            */
            for (c = 0; c < value; c++) {
			result[c] = c + 1;
		}
            
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= c <= value;
          loop assigns c, b[0 .. value-1], j;
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
          loop invariant 0 <= c <= value;
          loop assigns c, b[0 .. value-1], j;
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
