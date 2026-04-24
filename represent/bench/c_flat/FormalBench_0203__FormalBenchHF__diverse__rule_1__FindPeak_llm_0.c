int findPeak(int * data, int data_len, int array);

int findPeak(int * data, int data_len, int array) {

		int found = 0, top = array - 1;
		while (found < top) {
			int i = found + (top - found) / 2;
			if (data[i] < data[i + 1]) {
				found = i + 1;
			} else {
				top = i;
			}
		}
		return found;
}
