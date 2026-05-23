/*@
    requires num >= 0;
    assigns \nothing;
    ensures \result >= num;
*/
int evenBitSetNumber(int num);

 /*@
    requires num >= 0;
    assigns \nothing;
    ensures \result >= num;
*/
int evenBitSetNumber(int num) {

		int result = 0;
		int end = 0;
		int sum = num;
		/*@
		    loop invariant sum >= 0;
		    loop invariant result >= 0;
		    loop invariant 0 <= result;
		    loop assigns result, end, sum;
		    loop variant sum;
		*/
		while (sum > 0) {
			if (result % 2 == 1) {
				end |= (1 << result);
			}
			result++;
			sum >>= 1;
		}
		return (num | end);
}
