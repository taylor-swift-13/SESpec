/*@ 
    requires seed >= 0;
    requires 0 <= m <= seed;
    ensures \result >= 1;
    ensures \result == \prod(integer r = 1; r <= m; (seed - r + 1) / r);
    assigns \nothing;
*/
int binomialCoeff(int seed, int m);

int binomialCoeff(int seed, int m) {

		if (m > seed - m)
			m = seed - m;
		int b = 1;
		/*@
		loop invariant 1 <= r <= m + 1;
		loop invariant b == \prod(integer i = 1; i < r; (seed - i + 1) / i);
		loop assigns r, b;
		loop variant m - r + 1;
		*/
		for (int r = 1; r <= m; r++) {
			b = b * (seed - r + 1) / r;
		}
		return b;
}
