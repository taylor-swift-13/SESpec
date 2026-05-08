int foo286(int seed, int p);

int foo286(int seed, int p) {

		if (p > seed - p)
			p = seed - p;
		int b = 1;
		for (int r = 1; r <= p; r++) {
			b = b * (seed - r + 1) / r;
		}
		return b;
}
