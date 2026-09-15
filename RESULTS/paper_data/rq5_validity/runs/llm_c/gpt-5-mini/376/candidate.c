int binomialCoeff(int seed, int m);

/*@
    requires seed >= 0;
    requires 0 <= m && m <= seed;
    assigns \nothing;
    ensures \result == (\product integer r; 1 <= r <= (\old(m) <= seed - \old(m) ? \old(m) : seed - \old(m)); (seed - r + 1) / r);
    ensures \result >= 1;
*/
int binomialCoeff(int seed, int m) {

		if (m > seed - m)
			m = seed - m;
		int b = 1;
		/*@
		    loop invariant 1 <= r <= m + 1;
		    loop invariant b == (\product integer i; 1 <= i <= r-1; (seed - i + 1) / i);
		    loop invariant b >= 1;
		    loop assigns r, b;
		    loop variant m - r + 1;
		*/
		for (int r = 1; r <= m; r++) {
			b = b * (seed - r + 1) / r;
		}
		return b;
}
