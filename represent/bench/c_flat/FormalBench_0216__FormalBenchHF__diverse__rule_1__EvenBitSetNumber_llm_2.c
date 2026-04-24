int evenBitSetNumber(int num);

int evenBitSetNumber(int num) {

		int result = 0;
		int max = 0;
		int sum = num;
		while (sum > 0) {
			if (result % 2 == 1) {
				max |= (1 << result);
			}
			result++;
			sum >>= 1;
		}
		return (num | max);
}
