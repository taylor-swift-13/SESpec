int foo272(int * arr, int arr_len, int array);

int foo272(int * arr, int arr_len, int array) {

		int f = 0;
		for (int index = 0; index < arr_len; index++) {
			if (arr[index] == array) {
				f++;
			}
		}
		return f;
}
