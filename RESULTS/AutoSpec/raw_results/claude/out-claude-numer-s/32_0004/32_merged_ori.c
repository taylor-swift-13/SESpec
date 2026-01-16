/*@
  requires x >= 0 && x <= 10;
*/
int hoo32(int x) {
	
	int y = x * x;

	/*@
	loop invariant y == (\at(x, Pre) * \at(x, Pre)) + (x - \at(x, Pre));
	loop invariant y <= 1000 + (x - \at(x, Pre));
	loop invariant x * x <= 1000;
	loop invariant x * x <= 1000 + 2 * (x - (\at(x, Pre))) + 1;
	loop assigns y;
	loop assigns x;
	/*@;
	*/
	while(x * x <= 1000) {
		x = x + 1;
		y = y + 1;
	}

	/*@ assert y <= 1000; */
	return 0;
}

