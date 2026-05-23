/*@
    requires num > 0;
    ensures \result > 0;
    ensures \forall integer p; p > \result ==> num % p != 0;
    ensures \exists integer k; k > 0 && num == \result * k;
    assigns \nothing;
*/
int maxPrimeFactors(int num);

int maxPrimeFactors(int num) {

		int ret = 0;
		/*@
		loop invariant 2 <= j <= num + 1;
		loop invariant ret >= 0;
		loop assigns j, num, ret;
		loop variant num - j;
		*/
		for (int j = 2; j <= num; j++) {
			while (num % j == 0) {
				ret = j;
				num /= j;
			}
		}
		return ret;
}
