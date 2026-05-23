int foo395(int p);

int foo395(int p) {

		int odd = 0;
		for (int c = 1; c <= p; c++) {
			int tmp = 2 * c;
			odd = odd + (tmp * tmp * tmp * tmp);
		}
		return odd;
}
