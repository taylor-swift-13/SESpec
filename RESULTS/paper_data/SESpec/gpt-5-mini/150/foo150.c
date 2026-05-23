
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
  // Function contract for foo150:
  // The function returns the p-th odd element in 1..value if it exists;
  // otherwise it returns the p-th even element in 1..value if it exists;
  // otherwise it returns 0.
  requires value >= 0;
  requires p >= 1;
  assigns \nothing;
  ensures
    (
      // there exists i in [0, value) such that result is seq_val(i)
      // and that i is the index of the p-th odd number in 1..value
      (\exists integer i;
         0 <= i < value &&
         \result == seq_val(i) &&
         ((seq_val(i) % 2) == 1) &&
         // exactly p-1 odd elements before i
         (\numof integer k; 0 <= k < value; (k < i && (seq_val(k) % 2) == 1) ) == p-1
      )
    )
    ||
    (
      // otherwise there exists i in [0,value) with even value that is
      // the p-th even number and result equals seq_val(i)
      (\exists integer i;
         0 <= i < value &&
         \result == seq_val(i) &&
         ((seq_val(i) % 2) == 0) &&
         (\numof integer k; 0 <= k < value; (k < i && (seq_val(k) % 2) == 0) ) == p-1
      )
    )
    ||
    (
      // or no p-th odd nor p-th even exists and result is 0
      (\result == 0 &&
         (\numof integer k; 0 <= k < value; (seq_val(k) % 2) == 1) < p &&
         (\numof integer k; 0 <= k < value; (seq_val(k) % 2) == 0) < p
      )
    );
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
