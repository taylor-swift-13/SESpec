/*@
requires x >= 0 && x <= 10;
*/
int main23(int x) {
	
	int y = x * x;

	/*@
	loop invariant x >= 0 && x <= 10;
	loop invariant y >= x * x - (x - \at(x, Pre));
	loop invariant y <= x * x;
	loop invariant y == x * x - (\at(x, Pre) * \at(x, Pre)) + (x - \at(x, Pre));
	loop invariant \old(x) <= x;
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

