/*@
    requires value >= 0;
    ensures \result >= 0;
    ensures value == 0 ==> \result == 0;
    ensures value > 0 ==> \result >= 1;
    assigns \nothing;
*/
int countDigit(int value);

 /*@
    requires value >= 0;
    ensures \result >= 0;
    ensures value == 0 ==> \result == 0;
    ensures value > 0 ==> \result >= 1;
    assigns \nothing;
*/
int countDigit(int value) {

		int result = 0;
		/*@
		    loop invariant value >= 0;
		    loop invariant result >= 0;
		    loop invariant value >= 0;
		    loop assigns value, result;
		    loop variant value;
		*/
		while (value > 0) {
			value /= 10;
			result++;
		}
		return result;
}
