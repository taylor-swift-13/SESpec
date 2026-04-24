int findPeak(int * array, int array_len, int Array);

int findPeak(int * array, int array_len, int Array) {

		int found = 0, top = Array - 1;
		while (found < top) {
			int i = found + (top - found) / 2;
			if (array[i] < array[i + 1]) {
				found = i + 1;
			} else {
				top = i;
			}
		}
		return found;
}
