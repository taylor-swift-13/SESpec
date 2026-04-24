int hammingDistance(int num, int N);

int hammingDistance(int num, int N) {

		int n = 0;
		while (num != 0 || N != 0) {
			if ((num & 1) != (N & 1)) {
				n++;
			}
			num = num >> 1;
			N = N >> 1;
		}
		return n;
}
