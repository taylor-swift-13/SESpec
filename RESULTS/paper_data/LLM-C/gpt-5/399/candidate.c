int countDigit(int value);

/*@ logic integer digits(integer v) = (v <= 0 ? 0 : 1 + digits(v/10)); */

/*@ 
  requires \true;
  assigns \nothing;
  ensures \result == digits(\old(value));
*/
int countDigit(int value) {

		int result = 0;
		/*@
		  loop invariant result >= 0;
		  loop invariant digits(value) + result == digits(\at(value, Pre));
		  loop assigns value, result;
		  loop variant value;
		*/
		while (value > 0) {
			value /= 10;
			result++;
		}
		return result;
}
