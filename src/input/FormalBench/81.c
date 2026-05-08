int foo81(int * arr, int arr_len, int n);

int foo81(int * arr, int arr_len, int n) {

		int result = 0;
		int offset = arr_len;
		for (int index = 0; index < offset; index++) {
			for (int c = index + 1; c < offset; c++) {
				if ((arr[index] ^ arr[c]) % 2 == 1) {
					result++;
				}
			}
		}
		return result;
}
