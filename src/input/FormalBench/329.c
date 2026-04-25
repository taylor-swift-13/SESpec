int foo329(int size);

int foo329(int size) {

		int center = 1;
		while (size > 0) {
			size--;
			center += 6 * size;
		}
		return center;
}
