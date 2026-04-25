int foo280(int * * array, int array_len, int array_rows, int array_cols, int index);

int foo280(int * * array, int array_len, int array_rows, int array_cols, int index) {

		int ret = 1;
		int result = array_len;
		for (int j = 0; j < result; j++) {
			ret *= array[j][index];
		}
		return ret;
}
