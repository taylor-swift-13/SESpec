int foo247(int * tu, int tu_len, int array);

int foo247(int * tu, int tu_len, int array) {

		int ret = 0;
		for (int index = 0; index < tu_len; index++) {
			if (tu[index] == array) {
				ret++;
			}
		}
		return ret;
}
