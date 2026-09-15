int maxPrimeFactors(int num);

/* 3. FUNC CONTRACT */
int maxPrimeFactors(int num) {

		int result = 0;
		/* 2. LOOP INVARIANT */
		for (int c = 2; c <= num; c++) {
			/* 1. LOOP INVARIANT */
			while (num % c == 0) {
				result = c;
				num /= c;
			}
		}
		return result;
}
