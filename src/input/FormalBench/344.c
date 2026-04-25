const char * foo344(int code, int d, int n);

const char * foo344(int code, int d, int n) {

		if (code * code - 4 * d * n < 0) {
			return "No";
		} else if (code * code - 4 * d * n == 0) {
			return "Yes";
		} else {
			return "Yes";
		}
}
