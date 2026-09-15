
/*@
  // No extra predicates needed for this simple program
*/

int foo312(int count) {

	int ret = 0;
	int diameter = 2 * count;
	int center = diameter * diameter;
	
	/* >>> LOOP INVARIANT TO FILL <<< */
	
	/*@
	  /* Supplementary semantic invariants for outer loop */
	  loop invariant 1 <= i <= 2 * count + 1;
	  loop invariant 0 <= ret;
	  loop invariant diameter == 2 * \at(count,Pre);
	  loop invariant center == diameter * diameter;
	  loop invariant count == \at(count,Pre);
	  /* (a) functional progress: ret is the number of counted pairs (i',c)
	     processed so far; conservatively bounded above by processed pairs */
	  loop invariant ret <= (i - 1) * (2 * count);
	  /* (b) monotonicity: ret is non-decreasing as i increases */
	  loop invariant \exists integer processed_pairs;  processed_pairs == (i - 1) * (2 * count) ==> ret <= processed_pairs;
	  /* (c) existence/membership: processed prefix indices are within bounds */
	  loop invariant \forall integer ii; 1 <= ii < i ==> 1 <= ii && ii <= 2 * count;
	  /* (d) exit-implication: when loop finishes (i == 2*count+1) bounds imply final ret >= 0 */
	  loop invariant ret >= 0;
	  loop assigns i, ret;
	*/
	for (int i = 1; i <= 2 * count; i++) {
	
		/* >>> LOOP INVARIANT TO FILL <<< */
		
		/*@
		  loop invariant 1 <= c <= 2 * count + 1;
		  loop invariant 0 <= ret;
		  loop invariant diameter == 2 * \at(count,Pre);
		  loop invariant center == diameter * diameter;
		  loop invariant count == \at(count,Pre);
		  /* functional progress within inner loop: ret increases by at most (c-1) during this i */
		  loop invariant ret <= (i - 1) * (2 * count) + (c - 1);
		  /* monotonicity: c is within bounds and squares are non-negative */
		  loop invariant \forall integer k; 1 <= k <= 2 * count ==> 0 <= k * k;
		  loop assigns c, ret;
		*/
		for (int c = 1; c <= 2 * count; c++) {
			int diagnalLengthSquare = (i * i + c * c);
			if (diagnalLengthSquare <= center) {
				ret++;
			}
		}
		
	}
	
	return ret;
}
