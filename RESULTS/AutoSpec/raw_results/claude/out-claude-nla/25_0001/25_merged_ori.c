int unknown();
/*@
requires x >= 0;
*/
int main25(int x, int w) {
	
	int z = w * x;

	/*@
	loop invariant z == w * x;
	loop assigns z;
	loop assigns w;
	/*@;
	*/
	while(unknown())
	{
		w = w * x;
		z = z * x;
	}

	// @ assert z == w * x;
	return 0;
}