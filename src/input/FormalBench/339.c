int foo339(int num);

int foo339(int num) {

		int highest = 1;
		while (highest <= num) {
			highest *= 2;
		}
		return highest / 2;
}
