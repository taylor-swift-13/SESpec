int maxPrimeFactors(int num);

int maxPrimeFactors(int num) {

		int ret = 0;
		for (int j = 2; j <= num; j++) {
			/*@
			loop invariant 2 <= j <= num + 1;
			loop invariant ret == 0 || ret >= 2;
			loop invariant num > 0;
			loop invariant \forall integer k; 2 <= k < j ==> num % k != 0;
			loop assigns j;
			loop assigns ret;
			loop assigns num;
			*/
			while (num % j == 0) {
				ret = j;
				num /= j;
			}
		}
		return ret;
}
