/*@
    requires num > 0;
    ensures \result > 0;
    ensures \forall integer p; p > \result ==> num % p != 0;
    ensures \exists integer k; num == \result * k && k > 0 && (\forall integer p; p > 1 && p < \result ==> k % p != 0);
    assigns \nothing;
*/
int maxPrimeFactors(int num) {

		int result = 0;
		/*@
		loop invariant 2 <= j <= num + 1;
		loop invariant result > 0 ==> num % result == 0;
		loop invariant \forall integer p; p > result ==> num % p != 0;
		loop assigns j, num, result;
		loop variant num;
		*/
		for (int j = 2; j <= num; j++) {
			/*@
			loop invariant num >= 0;
			loop invariant result == j;
			loop assigns num;
			loop variant num;
			*/
			while (num % j == 0) {
				result = j;
				num /= j;
			}
		}
		return result;
}
