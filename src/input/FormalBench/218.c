int foo218(int num);

int foo218(int num) {

		int result = 0;
		int end = 0;
		int sum = num;
		while (sum > 0) {
			if (result % 2 == 1) {
				end |= (1 << result);
			}
			result++;
			sum >>= 1;
		}
		return (num | end);
}
