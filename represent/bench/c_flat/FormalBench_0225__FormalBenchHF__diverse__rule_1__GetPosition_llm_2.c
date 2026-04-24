int getPosition(int * positions, int positions_len, int b, int c);

int getPosition(int * positions, int positions_len, int b, int c) {

		int ret = 0;
		for (int p = 0; p < positions_len; p++) {
			if (positions[p] == b) {
				ret = p;
				break;
			}
		}
		return ret + c;
}
