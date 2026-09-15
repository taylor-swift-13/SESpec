
/*@
  requires num >= 1;
  behavior default:
    assumes num >= 1;
*/
        
int foo337(int num) {

	int ret = 0;
	
	/* >>> LOOP INVARIANT TO FILL <<< */
	/*@
	  loop invariant 2 <= j;
	  loop invariant num >= 1;
	  loop invariant \at(num,Pre) >= 1;
	  loop invariant ret >= 0;
	  loop assigns j, ret, num;
	*/
	for (int j = 2; j <= num; j++) {
		
		/*@
		  loop invariant 2 <= j;
		  loop invariant num >= 1;
		  loop invariant \at(num,Pre) >= 1;
		  loop invariant ret >= 0;
		  loop assigns j, num, ret;
		*/
		while (num % j == 0) {
			ret = j;
			num /= j;
		}
		
	}
	
	return ret;
}
