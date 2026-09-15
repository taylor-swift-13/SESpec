int lastTwoDigits(int num);

/* 2. FUNC CONTRACT */
int lastTwoDigits(int num) {

		int ret = 1;
		/* 1. LOOP INVARIANT */
		for (int number = 1; number <= num; number++) {
			ret *= number;
		}
		int result = (int) (ret % 100);
		return result;
}
