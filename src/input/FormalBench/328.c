int foo328(int num);

int foo328(int num) {

		int center = 1;
		while (num > 0) {
			num--;
			center += 6 * num;
		}
		return center;
}
