const char * foo343(int code, int n, int C);

const char * foo343(int code, int n, int C) {

		if (code * code - 4 * n * C < 0) {
			return "No";
		} else if (code * code - 4 * n * C == 0) {
			return "Yes";
		} else {
			return "Yes";
		}
}
