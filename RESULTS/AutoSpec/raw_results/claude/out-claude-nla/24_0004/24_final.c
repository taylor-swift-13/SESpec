/*@
requires x >= 0 && y >= 0;
*/
int main24(int x,int y) {
	
	int z = x * y;

	/*@
	loop invariant z == x * y;
	loop invariant 0 <= x;
	loop assigns z;
	loop assigns x;
	*/
	while(x > 0) {
		x = x - 1;
		z = z - y;
	}

	//@ assert z == 0;
	return 0;
}
