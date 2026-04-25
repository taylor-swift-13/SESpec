int foo124(int num);

int foo124(int num) {

		int result = 0;
		for (int c = 1; c <= num; c++) {
			int j = c;
			while (j != 0) {
				if ((j & 1) == 0) {
					result++;
				}
				j = j >> 1;
			}
		}
		return result;
}
