int largestPos(int * positions, int positions_len);

int largestPos(int * positions, int positions_len) {

		int largest = 0;
		for (int count = 0; count < positions_len; count++) {
			if (positions[count] > 0 && positions[count] > largest) {
				largest = positions[count];
			}
		}
		return largest;
}
