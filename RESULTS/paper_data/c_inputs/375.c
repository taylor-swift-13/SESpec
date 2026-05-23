int foo375(int num, int p);

int foo375(int num, int p) {

		if (p > num - p)
			p = num - p;
		int b = 1;
		for (int r = 1; r <= p; r++) {
			b = b * (num - r + 1) / r;
		}
		return b;
}
