int countPairs(int * pairs, int pairs_len, int array);

int countPairs(int * pairs, int pairs_len, int array) {

		int count = 0;
		int total = pairs_len;
		for (int index = 0; index < total - 1; index++) {
			for (int k = index + 1; k < total; k++) {
				if (pairs[index] != pairs[k]) {
					count++;
				}
			}
		}
		return count;
}
