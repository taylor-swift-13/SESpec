int countTuplex(int * arr, int arr_len, int num);

int countTuplex(int * arr, int arr_len, int num) {

		int ret = 0;
		for (int index = 0; index < arr_len; index++) {
			if (arr[index] == num) {
				ret++;
			}
		}
		return ret;
}
