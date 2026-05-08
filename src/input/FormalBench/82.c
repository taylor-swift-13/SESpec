int foo82(int * arr, int arr_len, int n);

int foo82(int * arr, int arr_len, int n) {

		int result = 0;
		int offset = arr_len;
		for (int c = 0; c < offset; c++) {
			for (int index = c + 1; index < offset; index++) {
				if ((arr[c] ^ arr[index]) % 2 == 1) {
					result++;
				}
			}
		}
		return result;
}
