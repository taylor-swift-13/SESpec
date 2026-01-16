/*@
requires x >= 0 && y >= 0;
*/
int main24(int x,int y) {
	
	int z = x * y;

	/*@
	Looking at this problem, I need to generate loop invariants for the while loop that will help prove the assertion `z == 0` after the loop.
	
	Let me analyze the loop:
	- Initial state: `z = x * y`, and we have `x >= 0 && y >= 0` from the precondition
	- Loop body: decrements `x` by 1 and decrements `z` by `y`
	- Loop continues while `x > 0`
	- After loop: need to prove `z == 0`
	
	The key insight is that the relationship `z == x * y` is maintained throughout the loop:
	- Initially: `z = x * y` (true by assignment)
	- Each iteration: if `z == x * y` before, then after `x' = x - 1` and `z' = z - y`, we have `z' = z - y = x*y - y = (x-1)*y = x'*y`
	- When loop exits: `x == 0`, so `z == 0 * y == 0`
	
	```c
	loop invariant z == x * y;
	loop invariant x >= 0;
	loop assigns x;
	loop assigns z;
	```
	*/
	while(x > 0) {
		x = x - 1;
		z = z - y;
	}

	// @ assert z == 0;
	return 0;
}
