/*@
requires x == 1 && x <= y;
*/
int main26(int x,int y) {
	
	int z=1;
	int w=1;

	/*@
	Looking at this problem, I need to generate loop invariants for the while loop that will help prove the assertion `w == z * y`.
	
	Let me analyze the loop:
	- `x` starts at 1 and increments by 1 each iteration until `x > y`
	- `w` accumulates the product: `w = 1 * 1 * 2 * 3 * ... * y` (factorial-like)
	- `z` accumulates the product: `z = 1 * 1 * 2 * 3 * ... * (y-1)` (stops before y)
	- The condition `x < y` ensures z doesn't multiply by y
	
	Key relationships:
	- When the loop exits, `x == y + 1`
	- `w` should be the product of all values from 1 to y
	- `z` should be the product of all values from 1 to (y-1)
	- Therefore: `w == z * y`
	
	```c
	loop invariant 1 <= x <= y + 1;
	loop invariant w == z * x;
	loop invariant x <= y ==> w == z * x;
	loop invariant x > y ==> w == z * y;
	loop assigns x;
	loop assigns w;
	loop assigns z;
	```
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
