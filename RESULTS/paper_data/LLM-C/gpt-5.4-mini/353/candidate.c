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
		int max = 0;
		int sum = num;
		/*@
		    loop invariant sum >= 0;
		    loop invariant result >= 0;
		    loop invariant sum <= num;
		    loop assigns result, max, sum;
		    loop variant sum;
		*/
		while (sum > 0) {
			if (result % 2 == 1) {
				max |= (1 << result);
			}
			result++;
			sum >>= 1;
		}
		return (num | max);
}
