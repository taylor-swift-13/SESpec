
/*@
  requires diff >= 0;
*/
int foo328(int diff) {

	int result = 0;
	int max = 0;
	
	/*@
	  loop invariant 1 <= c <= diff + 1;
	  loop invariant 0 <= result;
	  loop invariant 0 <= max;
	  loop assigns c, result;
	*/
	for (int c = 1; c <= diff; c++) {
		result += c * c * c;
	}
	
	/*@
	  loop invariant 1 <= c <= diff + 1;
	  loop invariant 0 <= result;
	  loop invariant 0 <= max;
	  loop invariant max == ( (c - 1) * c / 2 );
	  loop invariant (c == diff + 1) ==> (max == (diff * (diff + 1) / 2));
	  loop assigns c, max;
	*/
	for (int c = 1; c <= diff; c++) {
		max += c;
	}
            
	return result - max;
}
