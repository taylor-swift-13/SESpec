int getInvCount(int * indices, int indices_len, int num);

int getInvCount(int * indices, int indices_len, int num) {

		int ret = 0;

		for (int index = 0; index < num; index++) {
			for (int c = index + 1; c < num; c++) {
				if (indices[index] > indices[c]) {
					ret++;
				}
			}
		}
		return ret;
}
