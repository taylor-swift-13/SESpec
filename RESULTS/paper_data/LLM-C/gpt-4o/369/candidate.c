/*@
    requires value >= 0;
    requires p > 0;
    requires 0 <= dy < p;
    ensures \result == 0 || (\result % p == dy && \result <= value);
    ensures \result == 0 ==> \forall integer c; 1 <= c <= value ==> c % p != dy;
    ensures \result != 0 ==> \exists integer c; 1 <= c <= value && c % p == dy && \result == c;
    assigns \nothing;
*/
int findMaxVal(int value, int p, int dy) {

		int result = 0;
		/*@
		    loop invariant 1 <= c <= value + 1;
		    loop invariant result == 0 || (result % p == dy && result <= value);
		    loop invariant result == 0 ==> \forall integer k; 1 <= k < c ==> k % p != dy;
		    loop invariant result != 0 ==> \exists integer k; 1 <= k < c && k % p == dy && result == k;
		    loop assigns c, result;
		    loop variant value - c;
		*/
		for (int c = 1; c <= value; c++) {
			if ((c % p) == dy) {
				result = c;
			}
		}
		return result;
}
