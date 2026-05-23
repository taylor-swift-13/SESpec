/*@ 
    requires value >= 0;
    ensures \result >= 0;
    ensures value == 0 ==> \result == 0;
    ensures value > 0 ==> \result == \floor(\log10(value)) + 1;
    assigns \nothing;
*/
int countDigit(int value) {

		int result = 0;
		/*@
		loop invariant value >= 0;
		loop invariant result >= 0;
		loop invariant \forall integer k; 0 <= k < result ==> \floor(\log10(value * 10^k)) == result - k - 1;
		loop assigns value, result;
		loop variant value;
		*/
		while (value > 0) {
			value /= 10;
			result++;
		}
		return result;
}
