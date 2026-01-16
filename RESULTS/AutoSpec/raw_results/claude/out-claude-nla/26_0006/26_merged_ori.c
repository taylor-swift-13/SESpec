/*@
requires x == 1 && x <= y;
*/
int main26(int x,int y) {
	
	int z=1;
	int w=1;

	/*@
	loop invariant z <= w;
	loop invariant x >= 2 ==> z >= x - 1;
	loop invariant x >= 2 ==> w >= x;
	loop invariant 1 <= z;
	loop invariant 1 <= x;
	loop invariant 1 <= w;
	```c;
	```;
	Looking at the code and the existing invariant, I need to generate additional loop invariants that capture the relationship between variables `x`, `y`, `z`, and `w` throughout the loop execution.;
	loop invariant x <= y + 1;
	loop assigns z;
	loop assigns x;
	loop assigns w;
	*/
	while(x <= y)
	{
		w = w * x;
		if (x < y) {
			z = z * x;
		}
		x += 1;
	}

	// @ assert w == z * y;
	return 0;
}
