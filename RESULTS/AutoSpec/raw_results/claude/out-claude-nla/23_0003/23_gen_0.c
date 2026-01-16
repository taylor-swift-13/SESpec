/*@
requires x >= 0 && x <= 10;
*/
int main23(int x) {
	
	int y = x * x;

	/*@
	/*@ 
	loop invariant 0 <= x <= 10;
	loop invariant y == (x - \at(x, Pre)) * 1 + \at(y, Pre);
	loop invariant y <= x * x;
	*/
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

