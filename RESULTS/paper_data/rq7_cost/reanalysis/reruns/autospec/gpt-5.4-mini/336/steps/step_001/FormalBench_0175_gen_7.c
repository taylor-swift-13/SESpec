int maxPrimeFactors(int num);

int maxPrimeFactors(int num) {

		int result = 0;
		for (int c = 2; c <= num; c++) {
			/*@
			loop invariant 2 <= c <= num + 1;
			loop invariant result == 0 || result >= 2;
			loop invariant \forall integer k; 2 <= k < c ==> num % k != 0;
			loop assigns c;
			loop assigns result;
			loop assigns num;
			*/
			while (num % c == 0) {
				result = c;
				num /= c;
			}
		}
		return result;
}
