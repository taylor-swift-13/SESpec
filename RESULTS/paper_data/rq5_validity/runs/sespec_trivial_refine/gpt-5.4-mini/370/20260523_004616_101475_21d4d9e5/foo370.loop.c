
int foo370(int value, int k, int z) {

	int result = 0;

	/*@
	  loop invariant 1 <= c;
	  loop invariant result == 0 || (1 <= result && result <= value && result % k == z);
	  loop assigns c, result;
	*/
	for (int c = 1; c <= value; c++) {
		if ((c % k) == z) {
			result = c;
		}
	}

	return result;
}
