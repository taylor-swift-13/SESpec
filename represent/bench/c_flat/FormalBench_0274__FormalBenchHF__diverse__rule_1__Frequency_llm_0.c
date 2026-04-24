int frequency(int * arr, int arr_len, int b);

int frequency(int * arr, int arr_len, int b) {

		int f = 0;
		for (int index = 0; index < arr_len; index++) {
			if (arr[index] == b) {
				f++;
			}
		}
		return f;
}
