
/*@
  requires count >= 1;
  ensures \result >= 0;
  ensures (\result > 0) ==> (\exists integer ii, jj;
            1 <= ii && ii <= 2 * \at(count,Pre)
            && 1 <= jj && jj <= 2 * \at(count,Pre)
            && ii*ii + jj*jj <= (2 * \at(count,Pre))*(2 * \at(count,Pre)));
*/
int foo312(int count) {

	int ret = 0;
	int diameter = 2 * count;
	int center = diameter * diameter;
	
	/*@
	  loop invariant 0 <= ret;
	  loop invariant diameter == 2 * \at(count,Pre);
	  loop invariant center == diameter * diameter;
	  loop invariant count == \at(count,Pre);
	  loop invariant ret <= (i - 1) * (2 * \at(count,Pre));
	  loop invariant (\exists integer processed_pairs; processed_pairs == (i - 1) * (2 * \at(count,Pre)) ==> ret <= processed_pairs);
	  loop invariant \forall integer ii; 1 <= ii < i ==> 1 <= ii && ii <= 2 * \at(count,Pre);
	  loop assigns i, ret;
	*/
	for (int i = 1; i <= 2 * count; i++) {
	
		/*@
		  loop invariant 1 <= c;
		  loop invariant c <= 2 * count + 1;
		  loop invariant 0 <= ret;
		  loop invariant diameter == 2 * \at(count,Pre);
		  loop invariant center == diameter * diameter;
		  loop invariant count == \at(count,Pre);
		  loop invariant ret <= (i - 1) * (2 * \at(count,Pre)) + (c - 1);
		  loop invariant \forall integer k; 1 <= k && k <= 2 * \at(count,Pre) ==> 0 <= k * k;
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
