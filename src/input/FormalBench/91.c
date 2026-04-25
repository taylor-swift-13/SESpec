int foo91(int * pairs, int pairs_len, int array);

int foo91(int * pairs, int pairs_len, int array) {

		int count = 0;
		int total = pairs_len;
		for (int index = 0; index < total - 1; index++) {
			for (int c = index + 1; c < total; c++) {
				if (pairs[index] != pairs[c]) {
					count++;
				}
			}
		}
		return count;
}
