/*@
requires x >= 0 && x <= 10;
*/
int main23(int x) {
	
	int y = x * x;

	/*@
	loop invariant y <= x * x;
	loop invariant y <= x * x || x <= 10;
	loop invariant y <= x * x || 0 <= x;
	loop invariant x <= 10;
	loop invariant x < 10;
	loop invariant x < 10;
	loop invariant 0 <= x;
	loop invariant 0 <= x || x <= 10;
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

