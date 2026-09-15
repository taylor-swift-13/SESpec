/*@
    requires num >= 0;
    assigns \nothing;
    ensures \result >= 0;
    ensures \result == 0 <==> num <= 1;
*/
int maxPrimeFactors(int num);

int maxPrimeFactors(int num) {

		int ret = 0;
		/*@
		    loop invariant 2 <= j <= num + 1;
		    loop invariant ret >= 0;
		    loop assigns j, num, ret;
		    loop variant num - j + 1;
		*/
		for (int j = 2; j <= num; j++) {
			/*@
			    loop invariant num >= 0;
			    loop invariant ret == 0 || ret <= j;
			    loop assigns num, ret;
			    loop variant num;
			*/
			while (num % j == 0) {
				ret = j;
				num /= j;
			}
		}
		return ret;
}
