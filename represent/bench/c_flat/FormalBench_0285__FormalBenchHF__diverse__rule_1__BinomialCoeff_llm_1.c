int binomialCoeff(int seed, int m);

int binomialCoeff(int seed, int m) {

		if (m > seed - m)
			m = seed - m;
		int b = 1;
		for (int r = 1; r <= m; r++) {
			b = b * (seed - r + 1) / r;
		}
		return b;
}
