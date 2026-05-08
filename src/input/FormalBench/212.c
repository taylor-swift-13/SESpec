int foo212(int * positions, int positions_len);

int foo212(int * positions, int positions_len) {

		int largest = 0;
		for (int index = 0; index < positions_len; index++) {
			if (positions[index] > 0 && positions[index] > largest) {
				largest = positions[index];
			}
		}
		return largest;
}
