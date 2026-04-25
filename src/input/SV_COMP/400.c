int unknown();
int foo400() {
	int x = 0;
	int y = 0;

	while(unknown()) {
		y = y + 1;
		x = y * y;
	}

	return 0;
}
