int foo442(int x) {

	int y = x * x;

	while(x * x <= 1000) {
		x = x + 1;
		y = y + 1;
	}

	return 0;
}
