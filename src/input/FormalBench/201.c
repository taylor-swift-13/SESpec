int foo201(int * data, int data_len, int array);

int foo201(int * data, int data_len, int array) {

		int i = 0, top = array - 1;
		while (i < top) {
			int p = i + (top - i) / 2;
			if (data[p] < data[p + 1]) {
				i = p + 1;
			} else {
				top = p;
			}
		}
		return i;
}
