int maxPrimeFactors(int num);

int maxPrimeFactors(int num) {

		int ret = 0;
		for (int j = 2; j <= num; j++) {
			/*@
			loop invariant 2 <= j <= num + 1;
			loop invariant 0 <= ret <= num;
			loop invariant \forall integer k; 2 <= k < j ==> num % k != 0 || ret >= k;
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
