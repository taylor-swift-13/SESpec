int foo249(int * tu, int tu_len, int num);

int foo249(int * tu, int tu_len, int num) {

		int ret = 0;
		for (int index = 0; index < tu_len; index++) {
			if (tu[index] == num) {
				ret++;
			}
		}
		return ret;
}
