int foo143(int * array, int array_len, int Array);

int foo143(int * array, int array_len, int Array) {

		int ret = 0;
		int start = 0;
		for (int index = 0; index < Array; index++) {
			if (array[index] % 2 != 0) {
				start++;
				if (start % 2 != 0) {
					ret = array[index];
				}
			}
		}
		return ret;
}
