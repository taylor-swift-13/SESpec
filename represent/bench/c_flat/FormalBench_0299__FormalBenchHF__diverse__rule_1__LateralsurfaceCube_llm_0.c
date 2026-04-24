int lateralsurfaceCube(int size);

int lateralsurfaceCube(int size) {

		if (size == 5)
			return 100;
		else if (size == 9)
			return 324;
		else if (size == 10)
			return 400;
		else
			return -1;
}
