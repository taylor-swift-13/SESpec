int foo266(int code);

int foo266(int code) {

		int result = 0;
		while (code > 0) {
			if ((code & 1) == 1) {
				result++;
			}
			code = code >> 1;
		}
		return result;
}
