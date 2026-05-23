int findMaxVal(int value, int k, int z);

/*@
    requires value >= 0;
    requires k > 0;
    requires 0 <= z < k;
    assigns \nothing;
    ensures 0 <= \result <= value;
    ensures (\result == 0) <==> (\forall integer c; 1 <= c <= value ==> c % k != z);
    ensures (\result != 0) ==> (1 <= \result <= value && \result % k == z && \forall integer c; \result < c <= value ==> c % k != z);
*/
int findMaxVal(int value, int k, int z) {

		int result = 0;
		/*@
		  loop invariant 1 <= c <= value + 1;
		  loop invariant result == 0 ==> (\forall integer j; 1 <= j < c ==> j % k != z);
		  loop invariant result != 0 ==> (1 <= result < c && result % k == z && \forall integer j; result < j < c ==> j % k != z);
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
