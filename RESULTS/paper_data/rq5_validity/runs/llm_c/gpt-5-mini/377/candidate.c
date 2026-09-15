/*@
    requires seed >= 0;
    requires 0 <= p <= seed;
    assigns \nothing;
    logic integer choose(integer n, integer k) =
        k == 0 ? 1 : \product integer i; 1 <= i <= k; (n - i + 1)/i;
    ensures \result == choose(\old(seed), \old(p));
*/
int binomialCoeff(int seed, int p) {

		if (p > seed - p)
			p = seed - p;
		int b = 1;
		/*@
		    loop invariant 1 <= r <= p + 1;
		    loop invariant b == (\product integer i; 1 <= i <= r-1; (seed - i + 1)/i);
		    loop assigns r, b;
		    loop variant p - r + 1;
		*/
		for (int r = 1; r <= p; r++) {
			b = b * (seed - r + 1) / r;
		}
		return b;
}
