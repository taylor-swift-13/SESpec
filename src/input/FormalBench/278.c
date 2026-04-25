int foo278(int * * K, int K_len, int K_rows, int K_cols, int index);

int foo278(int * * K, int K_len, int K_rows, int K_cols, int index) {

		int ret = 1;
		int result = K_len;
		for (int j = 0; j < result; j++) {
			ret *= K[j][index];
		}
		return ret;
}
