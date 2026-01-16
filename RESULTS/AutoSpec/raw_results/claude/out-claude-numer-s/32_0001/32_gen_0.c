/*@
  requires x >= 0 && x <= 10;
*/
int hoo32(int x) {
	
	int y = x * x;

	/*@
	loop invariant x * x <= 1000;
	loop invariant y == (x - (x - (y - x + 1))) * (x - (x - (y - x + 1)));
	loop invariant y <= 1000;
	loop assigns x;
	loop assigns y;
	*/
	while(x * x <= 1000) {
		x = x + 1;
		y = y + 1;
	}

	/*@ assert y <= 1000; */
	return 0;
}

