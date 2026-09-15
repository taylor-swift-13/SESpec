/*@
    requires p != 0;
    requires value >= 0;
    assigns \nothing;
    ensures 0 <= \result <= value;
    ensures (\result == 0) <==> (\forall integer c; 1 <= c <= value ==> c % p != z);
    ensures \result != 0 ==> (\result % p == z && \forall integer j; 1 <= j <= value && j % p == z ==> j <= \result);
*/
int findMaxVal(int value, int p, int z);

int findMaxVal(int value, int p, int z) {

		int result = 0;
		/*@
		    loop invariant 1 <= c <= value + 1;
		    loop invariant 0 <= result <= value;
		    loop invariant (result == 0) <==> (\forall integer j; 1 <= j < c ==> j % p != z);
		    loop invariant result != 0 ==> (\exists integer j; 1 <= j < c && j % p == z && j <= result);
		    loop assigns c, result;
		    loop variant value - c + 1;
		*/
		for (int c = 1; c <= value; c++) {
			if ((c % p) == z) {
				result = c;
			}
		}
		return result;
}
