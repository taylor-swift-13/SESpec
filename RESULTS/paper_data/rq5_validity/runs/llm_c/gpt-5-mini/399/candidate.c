int countDigit(int value);

/*@
    requires value >= 0;
    assigns \nothing;
    ensures \old(value) == 0 <==> \result == 0;
    ensures \old(value) > 0 ==> \result >= 1;
    ensures \old(value) > 0 ==> \old(value) / \pow(10, \result-1) >= 1;
    ensures \old(value) > 0 ==> \old(value) / \pow(10, \result) == 0;
*/
int countDigit(int value) {

		int result = 0;
		/*@
		    loop invariant result >= 0;
		    loop invariant value >= 0;
		    loop invariant value == \old(value) / \pow(10, result);
		    loop assigns value, result;
		    loop variant value;
		*/
		while (value > 0) {
			value /= 10;
			result++;
		}
		return result;
}
