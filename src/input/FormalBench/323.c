int foo323(int p);

int foo323(int p) {

		int even = 0;
		for (int c = 1; c <= p; c++) {
			int tmp = 2 * c;
			even = even + (tmp * tmp * tmp * tmp);
		}
		return even;
}
