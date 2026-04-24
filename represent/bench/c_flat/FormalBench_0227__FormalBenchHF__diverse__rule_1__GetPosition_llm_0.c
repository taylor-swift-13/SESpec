int getPosition(int * positions, int positions_len, int b, int p);

int getPosition(int * positions, int positions_len, int b, int p) {

		int ret = 0;
		for (int j = 0; j < positions_len; j++) {
			if (positions[j] == b) {
				ret = j;
				break;
			}
		}
		return ret + p;
}
