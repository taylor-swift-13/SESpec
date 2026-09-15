
/*@
  requires value >= 0;
  requires k > 0;
  requires 0 <= z < k;
  assigns \nothing;
  ensures \result == 0 || (1 <= \result && \result <= value && \result % k == z);
*/
int foo370(int value, int k, int z) {

	int result = 0;

	/*@
	  loop invariant 1 <= c <= value + 1;
	  loop invariant result == 0 || (1 <= result && result < c && result % k == z);
	  loop assigns c, result;
	  loop variant value - c + 1;
	*/
	for (int c = 1; c <= value; c++) {
		if ((c % k) == z) {
			result = c;
		}
	}

	return result;
}
