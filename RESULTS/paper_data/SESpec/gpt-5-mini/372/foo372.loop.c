
/*@
  logic integer count_divs_upto(integer n, integer upto) =
    upto <= 0 ? 0 :
    ((n % upto == 0) ? 1 + count_divs_upto(n, upto - 1) : count_divs_upto(n, upto - 1));
*/
        
int foo372(int num) {

	int div = 0;
		
	/* >>> LOOP INVARIANT TO FILL <<< */
	
	/*@
	  loop invariant c >= 1;
	  loop invariant div >= 0;
	  loop invariant div == count_divs_upto(num, c - 1);
	  loop invariant num == \at(num,Pre);
	  loop assigns c, div;
	*/
	for (int c = 1; c <= num; c++) {
		if (num % c == 0) {
			div++;
		}
	}
			
	return div;
}
