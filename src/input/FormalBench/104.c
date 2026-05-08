int foo104(int * pairs, int pairs_len, int num, int p);

int foo104(int * pairs, int pairs_len, int num, int p) {

		int ret = 0;
		for (int index = 0; index < num; index++) {
			for (int j = index + 1; j < num; j++) {
				if (pairs[index] + pairs[j] == p) {
					ret++;
				}
			}
		}
		return ret;
}
