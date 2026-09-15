int findMaxVal(int value, int k, int z);

/*@ 
  requires k != 0;
  assigns \nothing;
  ensures \result == 0 <==> (\forall integer c; 1 <= c <= value ==> c % k != z);
  ensures \result == 0 || (1 <= \result && \result <= value);
  ensures \forall integer c; 1 <= c <= value ==> (c % k == z ==> c <= \result);
  ensures \result == 0 || \result % k == z;
*/
int findMaxVal(int value, int k, int z) {

		int result = 0;
		/*@
		  loop invariant 1 <= c <= value + 1;
		  loop invariant 0 <= result <= c - 1;
		  loop invariant result == 0 || result % k == z;
		  loop invariant \forall integer t; 1 <= t < c ==> (t % k == z ==> t <= result);
		  loop assigns result, c;
		  loop variant value - c + 1;
		*/
		for (int c = 1; c <= value; c++) {
			if ((c % k) == z) {
				result = c;
			}
		}
		return result;
}
