/*@
    requires k > 0;
    requires 0 <= z < k;
    requires value >= 0;
    assigns \nothing;
    ensures 0 <= \result <= value;
    ensures \result == 0 || (\result % k) == z;
    ensures \forall integer c; 0 <= c <= value && (c % k) == z ==> c <= \result;
*/
int findMaxVal(int value, int k, int z);

 /*@ 
    requires k > 0;
    requires 0 <= z < k;
    requires value >= 0;
    assigns \nothing;
    ensures 0 <= \result <= value;
    ensures \result == 0 || (\result % k) == z;
    ensures \forall integer c; 0 <= c <= value && (c % k) == z ==> c <= \result;
*/
int findMaxVal(int value, int k, int z) {

		int result = 0;
		/*@
		    loop invariant 1 <= c <= value + 1;
		    loop invariant 0 <= result <= value;
		    loop invariant result == 0 || (result % k) == z;
		    loop invariant \forall integer t; 0 <= t < c && (t % k) == z ==> t <= result;
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
