int bigDiff(int * arr, int arr_len);

int bigDiff(int * arr, int arr_len) {

		int result = arr[0];
		int sum = arr[0];
		for (int n = 1; n < arr_len; n++) {
			if (arr[n] > result) {
				result = arr[n];
			}
			if (arr[n] < sum) {
				sum = arr[n];
			}
		}
		return result - sum;
}
