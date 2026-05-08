int foo302(int num, int b, int r);

int foo302(int num, int b, int r) {

		int result = 0;
		while (r > 0) {
			r -= 1;
			num *= 10;
			result = num / b;
			num %= b;
		}
		return result;
}
