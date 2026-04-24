int findKProduct(int * * array, int array_len, int array_rows, int array_cols, int index);

int findKProduct(int * * array, int array_len, int array_rows, int array_cols, int index) {

		int result = 1;
		int prod = array_len;
		for (int j = 0; j < prod; j++) {
			result *= array[j][index];
		}
		return result;
}
