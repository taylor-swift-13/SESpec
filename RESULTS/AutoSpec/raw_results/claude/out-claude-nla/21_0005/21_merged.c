int unknown();
int main21() {
	int x = 0;
	int y = 0;

	/*@
	loop invariant y == \floor(\sqrt(x));
	loop invariant \exists integer k; 0 <= k <= y && x == k * k;
	loop invariant x == y * y;
	loop invariant \true;
	loop invariant \false || x == y * y;
	loop invariant 0 <= y;
	loop invariant 0 <= x;
	loop assigns y;
	loop assigns x;
	*/
	while(unknown()) {
		y = y + 1;
		x = y * y;
	}

	//@ assert x == y * y;*/
	return 0;
}
