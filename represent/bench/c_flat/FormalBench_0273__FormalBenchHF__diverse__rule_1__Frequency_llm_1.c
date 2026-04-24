int frequency(int * data, int data_len, int b);

int frequency(int * data, int data_len, int b) {

		int f = 0;
		for (int index = 0; index < data_len; index++) {
			if (data[index] == b) {
				f++;
			}
		}
		return f;
}
