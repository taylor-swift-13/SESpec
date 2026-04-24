int evenPowerSum(int p);

int evenPowerSum(int p) {

		int even = 0;
		for (int c = 1; c <= p; c++) {
			int count = 2 * c;
			even = even + (count * count * count * count);
		}
		return even;
}
