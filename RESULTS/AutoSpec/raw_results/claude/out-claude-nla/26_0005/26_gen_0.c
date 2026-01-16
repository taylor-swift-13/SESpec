/*@
requires x == 1 && x <= y;
*/
int main26(int x,int y) {
	
	int z=1;
	int w=1;

	/*@
	/*@ 
	  loop invariant  x_start <= x <= y + 1;
	  loop invariant  w == \product(integer k; x_start <= k < x; k);
	  loop invariant  z == (x <= y) ? \product(integer k; x_start <= k < y; k) : \product(integer k; x_start <= k <= y; k);
	  loop assigns x, w, z;
	*/
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
