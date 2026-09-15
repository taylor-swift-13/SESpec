/*@
    requires value >= 0;
    requires k > 0;
    requires 0 <= z < k;
    ensures \result == 0 || (\result % k == z && \result <= value);
    ensures \result == 0 ==> \forall integer c; 1 <= c <= value ==> c % k != z;
    ensures \result != 0 ==> \exists integer c; 1 <= c <= value && c % k == z && \result == c;
    assigns \nothing;
*/
int findMaxVal(int value, int k, int z);

int findMaxVal(int value, int k, int z) {

		int result = 0;
		/*@
		    loop invariant 1 <= c <= value + 1;
		    loop invariant result == 0 || (result % k == z && result <= value);
		    loop invariant result == 0 ==> \forall integer d; 1 <= d < c ==> d % k != z;
		    loop invariant result != 0 ==> \exists integer d; 1 <= d < c && d % k == z && result == d;
		    loop assigns c, result;
		    loop variant value - c;
		*/
		for (int c = 1; c <= value; c++) {
			if ((c % k) == z) {
				result = c;
			}
		}
		return result;
}
