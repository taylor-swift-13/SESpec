/*@
    requires num >= 0;
    assigns \nothing;
    ensures \result >= 0;
    ensures \result == 0 || (\forall integer k; 2 <= k <= num ==> k <= \result || num % k != 0);
*/
int maxPrimeFactors(int num) {

		int result = 0;
		/*@
		    loop invariant 2 <= j <= num + 1;
		    loop invariant result >= 0;
		    loop assigns j, num, result;
		    loop variant num - j + 1;
		*/
		for (int j = 2; j <= num; j++) {
			/*@
			    loop invariant j >= 2;
			    loop invariant num >= 0;
			    loop invariant result == 0 || result <= j;
			    loop assigns num, result;
			    loop variant num;
			*/
			while (num % j == 0) {
				result = j;
				num /= j;
			}
		}
		return result;
}
