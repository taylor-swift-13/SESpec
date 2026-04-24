long long Perimeter(short x);
long long Perimeter_2(int x);
long long Perimeter_3(long long x);
long long Perimeter_4(int x, int y);
long long Perimeter_5(int x, int y, int z);
long long Perimeter_6(int w, int x, int y, int z);

long long Perimeter(short x) {

	long squarePerimeter = 4 * (long)x;
	return squarePerimeter;
}

long long Perimeter_2(int x) {

	long pentagonPerimeter = 5 * (long)x;
	return pentagonPerimeter;
}

long long Perimeter_3(long long x) {

	long hexagonalPerimeter = 6 * x;
	return hexagonalPerimeter;
}

long long Perimeter_4(int x, int y) {

	long perimeterRectangle = 2*((long)x + (long)y);
	return perimeterRectangle;
}

long long Perimeter_5(int x, int y, int z) {

	long trianglePerimeter = (long)x + (long)y + (long)z;
	return trianglePerimeter;
}

long long Perimeter_6(int w, int x, int y, int z) {

	long trapeziumPerimeter = (long)w + (long)x + (long)y + (long)z;
	return trapeziumPerimeter;
}
