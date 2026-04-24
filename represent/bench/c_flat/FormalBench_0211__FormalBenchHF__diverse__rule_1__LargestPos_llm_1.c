int largestPos(int * positions, int positions_len);

int largestPos(int * positions, int positions_len) {

		int result = 0;
		for (int index = 0; index < positions_len; index++) {
			if (positions[index] > 0 && positions[index] > result) {
				result = positions[index];
			}
		}
		return result;
}
