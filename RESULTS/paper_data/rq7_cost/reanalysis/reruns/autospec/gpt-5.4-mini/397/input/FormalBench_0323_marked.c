int evenPowerSum(int p);

/* 2. FUNC CONTRACT */
int evenPowerSum(int p) {

		int even = 0;
		/* 1. LOOP INVARIANT */
		for (int c = 1; c <= p; c++) {
			int tmp = 2 * c;
			even = even + (tmp * tmp * tmp * tmp);
		}
		return even;
}
