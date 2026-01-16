/*@
requires x >= 0 && x <= 10;
*/
int main23(int x) {
	
	int y = x * x;

	/*@
	loop invariant y <= x * x;
	loop invariant y < x * x;
	loop invariant y < x * x;
	loop invariant y < x * x;
	loop invariant x >= 0 && x <= 10;
	loop invariant x * x - (x - \old(x)) <= y;
	loop invariant x * x - (x - \old(x)) <= y || y <= x * x;
	loop invariant x * x - (x - \old(x)) < y;
	loop invariant \old(x) <= x;
	loop invariant \old(x) <= x || y <= x * x;
	loop invariant \old(x) <= x || x * x - (x - \old(x)) <= y;
	loop invariant \old(x) < x;
	loop assigns y;
	loop assigns x;
	*/
	while(unknown()) {
		x = x + 1;
		y = y + 1;
	}

	// @ assert y <= x * x;
	return 0;
}

