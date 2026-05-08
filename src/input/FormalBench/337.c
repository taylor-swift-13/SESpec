int foo337(int base);

int foo337(int base) {

		int highest = 1;
		while (highest <= base) {
			highest *= 2;
		}
		return highest / 2;
}
