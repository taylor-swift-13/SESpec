/*@
requires x == 1 && x <= y;
*/
int main26(int x,int y) {
	
	int z=1;
	int w=1;

	/*@
	loop invariant z * y == w || x <= y;
	loop invariant x <= y + 1;
	loop invariant w == z * (x > y ? y : x - 1);
	loop invariant w == z * ((x <= y) ? (x - 1) : y);
	loop invariant 1 <= x;
	loop invariant x >= 1 && x <= y + 1;
	loop assigns z;
	loop assigns x;
	loop assigns w;
	*/
	while(x <= y)
	{
		w = w * x;
		if (x < y) {
			z = z * x;
		}
		x += 1;
	}

	// @ assert w == z * y;
	return 0;
}
