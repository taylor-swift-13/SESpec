long long Perimeter(short x);
long long Perimeter_2(int x);
long long Perimeter_3(long long x);
long long Perimeter_4(int x, int y);
long long Perimeter_5(int x, int y, int z);
long long Perimeter_6(int w, int x, int y, int z);

/*@
    assigns \nothing;
    ensures \result == 4LL * (long long)x;
*/
long long Perimeter(short x) {

	long squarePerimeter = 4 * (long)x;
	return squarePerimeter;
}

/*@
    assigns \nothing;
    ensures \result == 5LL * (long long)x;
*/
long long Perimeter_2(int x) {

	long pentagonPerimeter = 5 * (long)x;
	return pentagonPerimeter;
}

/*@
    assigns \nothing;
    ensures \result == 6LL * x;
*/
long long Perimeter_3(long long x) {

	long hexagonalPerimeter = 6 * x;
	return hexagonalPerimeter;
}

/*@
    assigns \nothing;
    ensures \result == 2LL * ((long long)x + (long long)y);
*/
long long Perimeter_4(int x, int y) {

	long perimeterRectangle = 2*((long)x + (long)y);
	return perimeterRectangle;
}

/*@
    assigns \nothing;
    ensures \result == (long long)x + (long long)y + (long long)z;
*/
long long Perimeter_5(int x, int y, int z) {

	long trianglePerimeter = (long)x + (long)y + (long)z;
	return trianglePerimeter;
}

/*@
    assigns \nothing;
    ensures \result == (long long)w + (long long)x + (long long)y + (long long)z;
*/
long long Perimeter_6(int w, int x, int y, int z) {

	long trapeziumPerimeter = (long)w + (long)x + (long)y + (long)z;
	return trapeziumPerimeter;
}
