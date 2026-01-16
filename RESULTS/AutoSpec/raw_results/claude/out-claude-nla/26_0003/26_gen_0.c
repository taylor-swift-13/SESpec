/*@
requires x == 1 && x <= y;
*/
int main26(int x,int y) {
	
	int z=1;
	int w=1;

	/*@
	loop invariant 1 <= x <= y + 1;
	loop invariant w == z * x || x > y;
	loop invariant z == (\product integer k; 1 <= k < x ? k : 1);
	loop invariant w == (\product integer k; 1 <= k <= x - 1 ? k : 1);
	loop invariant x <= y + 1;
	loop invariant x >= 1;
	loop invariant x >= 1 && x <= y + 1;
	loop invariant x <= y + 1;
	loop invariant 1 <= x;
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
