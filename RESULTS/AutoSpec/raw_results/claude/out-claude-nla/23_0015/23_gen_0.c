/*@
requires x >= 0 && x <= 10;
*/
int main23(int x) {
	
	int y = x * x;

	/*@
	Looking at this code, I need to generate loop invariants for the while loop that differ from any existing annotations (there are none shown below the infill location).
	
	Given:
	- Initial: `x` is between 0 and 10, `y = x * x`
	- Loop: both `x` and `y` increment by 1
	- Postcondition: `y <= x * x`
	
	Let me trace the relationship:
	- Initially: `y = x²`
	- After 1 iteration: `y = x² + 1`, `x` becomes `x + 1`, so `y = (x-1)² + 1 = x² - 2x + 1 + 1 = x² - 2x + 2`
	- After k iterations: `y = x₀² + k` and `x = x₀ + k`, so `y = (x - k)² + k`
	
	The key invariant is that `y` starts equal to `x²` but grows more slowly than `x²` as the loop progresses.
	
	```c
	loop invariant x >= 0;
	loop invariant y >= 0;
	loop invariant x >= 0 ==> y <= x * x;
	loop invariant \at(y, Pre) == \at(x, Pre) * \at(x, Pre);
	loop invariant x - \at(x, Pre) == y - \at(y, Pre);
	```
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

