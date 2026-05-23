/*@
    requires value >= 0;
    requires p > 0;
    requires 0 <= dy < p;
    assigns \nothing;
    ensures 0 <= \result <= value;
    ensures \result == 0 || (\result % p) == dy;
    ensures \result == 0 ==> \forall integer c; 1 <= c <= value ==> (c % p) != dy;
    ensures \result != 0 ==> \forall integer c; \result < c <= value ==> (c % p) != dy;
*/
int findMaxVal(int value, int p, int dy);

 /*@
    requires value >= 0;
    requires p > 0;
    requires 0 <= dy < p;
    assigns \nothing;
    ensures 0 <= \result <= value;
    ensures \result == 0 || (\result % p) == dy;
    ensures \result == 0 ==> \forall integer c; 1 <= c <= value ==> (c % p) != dy;
    ensures \result != 0 ==> \forall integer c; \result < c <= value ==> (c % p) != dy;
*/
int findMaxVal(int value, int p, int dy) {

		int result = 0;
		/*@
		    loop invariant 1 <= c <= value + 1;
		    loop invariant 0 <= result <= value;
		    loop invariant result == 0 || (result % p) == dy;
		    loop invariant result == 0 ==> \forall integer k; 1 <= k < c ==> (k % p) != dy;
		    loop invariant result != 0 ==> \forall integer k; result < k < c ==> (k % p) != dy;
		    loop assigns c, result;
		    loop variant value - c + 1;
		*/
		for (int c = 1; c <= value; c++) {
			if ((c % p) == dy) {
				result = c;
			}
		}
		return result;
}
