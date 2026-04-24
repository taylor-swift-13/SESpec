int getPosition(int * positions, int positions_len, int array, int b);

int getPosition(int * positions, int positions_len, int array, int b) {

		int ret = 0;
		for (int p = 0; p < positions_len; p++) {
			if (positions[p] == array) {
				ret = p;
				break;
			}
		}
		return ret + b;
}
