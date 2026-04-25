int foo217(int num);

int foo217(int num) {

		int even = 0;
		int result = 0;
		int sum = num;
		while (sum > 0) {
			if (even % 2 == 1) {
				result |= (1 << even);
			}
			even++;
			sum >>= 1;
		}
		return (num | result);
}
