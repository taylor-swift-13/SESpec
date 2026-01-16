/*@
requires x == 1 && x <= y;
*/
int main26(int x,int y) {
	
	int z=1;
	int w=1;

	/*@
	loop invariant z == (x <= y ? \product(1, x - 1, \lambda integer k; k) : \product(1, y - 1, \lambda integer k; k));
	loop invariant x >= 1 && x <= y + 1;
	loop invariant w == z * (x > y ? 1 : y);
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
