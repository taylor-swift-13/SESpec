
/*@
  // no additional logic function needed
*/
int foo369(int value, int p, int dy) {

	int result = 0;

	/* >>> LOOP INVARIANT TO FILL <<< */
	/*@
	  loop invariant 1 <= c;
	  loop invariant result == 0 || (1 <= result && result < c && (result % p) == dy);
	  loop assigns c, result;
	*/
	for (int c = 1; c <= value; c++) {
		if ((c % p) == dy) {
			result = c;
		}
	}

	return result;
}
