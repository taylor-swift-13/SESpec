const char * checkSolution(int code, int n, int d);

const char * checkSolution(int code, int n, int d) {

		if (code * code - 4 * n * d < 0) {
			return "No";
		} else if (code * code - 4 * n * d == 0) {
			return "Yes";
		} else {
			return "Yes";
		}
}
