/*@
requires x >= 0 && x <= 10;
*/
int main23(int x) {
	
	int y = x * x;

	/*@
	/*@ 
	  loop invariant x >= \old(x) && x <= 10;
	  loop invariant y == \old(y) + (x - \old(x));
	  loop assigns x, y;
	*/
	*/
	while(unknown()) {
		x = x + 1;
		y = y + 1;
	}

	// @ assert y <= x * x;
	return 0;
}

