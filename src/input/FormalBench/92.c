int foo92(int * arr, int arr_len);

int foo92(int * arr, int arr_len) {

		int result = arr[0];
		int num = arr[0];
		for (int n = 1; n < arr_len; n++) {
			if (arr[n] > result) {
				result = arr[n];
			}
			if (arr[n] < num) {
				num = arr[n];
			}
		}
		return result - num;
}
