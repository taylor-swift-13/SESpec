int foo30(int n);

int foo30(int n) {

		if (n == 0) {
			return 3;
		}
		if (n == 1) {
			return 3;
		}
		if (n == 2) {
			return 5;
		}
		int end = 5;
		int total = 3;
		int e = 0;
		int f = 2;
		while (n > 2) {
			int i = total + e;
			end = end + i;
			total = e;
			e = f;
			f = i;
			n--;
		}
		return end;
}
