int maxPrimeFactors(int num);

/* 3. FUNC CONTRACT */
int maxPrimeFactors(int num) {

		int ret = 0;
		/* 2. LOOP INVARIANT */
		for (int j = 2; j <= num; j++) {
			/* 1. LOOP INVARIANT */
			while (num % j == 0) {
				ret = j;
				num /= j;
			}
		}
		return ret;
}
