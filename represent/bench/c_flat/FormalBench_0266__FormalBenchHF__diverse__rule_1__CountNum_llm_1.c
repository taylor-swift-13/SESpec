int countNum(int code);

int countNum(int code) {

		int result = 0;
		while (code > 0) {
			if ((code & 1) == 1) {
				result++;
			}
			code = code >> 1;
		}
		return result;
}
