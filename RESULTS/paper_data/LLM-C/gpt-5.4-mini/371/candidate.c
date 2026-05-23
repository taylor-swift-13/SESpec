/*@
    requires p > 0;
    requires value >= 0;
    requires 0 <= z < p;
    assigns \nothing;
    ensures 0 <= \result <= value;
    ensures \result == 0 || (\result % p) == z;
    ensures \result == 0 || \forall integer c; 1 <= c <= value && (c % p) == z ==> c <= \result;
*/
int findMaxVal(int value, int p, int z);

 /*@
    requires p > 0;
    requires value >= 0;
    requires 0 <= z < p;
    assigns \nothing;
    ensures 0 <= \result <= value;
    ensures \result == 0 || (\result % p) == z;
    ensures \result == 0 || \forall integer c; 1 <= c <= value && (c % p) == z ==> c <= \result;
*/
int findMaxVal(int value, int p, int z) {

		int result = 0;
		/*@
		    loop invariant 1 <= c <= value + 1;
		    loop invariant 0 <= result <= value;
		    loop invariant result == 0 || (result % p) == z;
		    loop invariant result == 0 || \forall integer k; 1 <= k < c && (k % p) == z ==> k <= result;
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
