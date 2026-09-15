int findNthDigit(int num, int c, int r);

/* 2. FUNC CONTRACT */
int findNthDigit(int num, int c, int r) {

		int result = 0;
		/* 1. LOOP INVARIANT */
		while (r > 0) {
			r -= 1;
			num *= 10;
			result = num / c;
			num %= c;
		}
		return result;
}
