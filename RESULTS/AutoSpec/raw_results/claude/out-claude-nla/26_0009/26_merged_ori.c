/*@
requires x == 1 && x <= y;
*/
int main26(int x,int y) {
	
	int z=1;
	int w=1;

	/*@
	loop invariant x <= y + 1;
	loop invariant w == \product(1, x - 1, \lambda integer k; k);
	loop invariant 1 <= x;
	loop invariant (x > y) ==> (z == \product(1, y - 1, \lambda integer k; k));
	loop invariant (x <= y) ==> (z == \product(1, x - 1, \lambda integer k; k));
	loop assigns z;
	loop assigns x;
	loop assigns w;
	/*@;
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
