int foo90(int * p, int p_len, int array);

int foo90(int * p, int p_len, int array) {

		int count = 0;
		int total = p_len;
		for (int index = 0; index < total - 1; index++) {
			for (int c = index + 1; c < total; c++) {
				if (p[index] != p[c]) {
					count++;
				}
			}
		}
		return count;
}
