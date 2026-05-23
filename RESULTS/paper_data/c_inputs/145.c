long long foo70_helper1_c145(short x);
long long foo70_helper2_c145(int x);
long long foo70_helper3_c145(long long x);
long long foo70_helper4_c145(int x, int y);
long long foo70_helper5_c145(int x, int y, int z);
long long foo145(int w, int x, int y, int z);

long long foo70_helper1_c145(short x) {

	long squarePerimeter = 4 * (long)x;
	return squarePerimeter;
}

long long foo70_helper2_c145(int x) {

	long pentagonPerimeter = 5 * (long)x;
	return pentagonPerimeter;
}

long long foo70_helper3_c145(long long x) {

	long hexagonalPerimeter = 6 * x;
	return hexagonalPerimeter;
}

long long foo70_helper4_c145(int x, int y) {

	long perimeterRectangle = 2*((long)x + (long)y);
	return perimeterRectangle;
}

long long foo70_helper5_c145(int x, int y, int z) {

	long trianglePerimeter = (long)x + (long)y + (long)z;
	return trianglePerimeter;
}

long long foo145(int w, int x, int y, int z) {

	long trapeziumPerimeter = (long)w + (long)x + (long)y + (long)z;
	return trapeziumPerimeter;
}
