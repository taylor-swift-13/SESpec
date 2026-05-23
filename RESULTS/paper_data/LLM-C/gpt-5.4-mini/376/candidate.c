/*@
    requires m >= 0;
    requires seed >= 0;
    requires m <= seed;
    assigns \nothing;
    ensures \result >= 0;
*/
int binomialCoeff(int seed, int m);

 
/*@
    requires m >= 0;
    requires seed >= 0;
    requires m <= seed;
    assigns \nothing;
    ensures \result >= 0;
*/
int binomialCoeff(int seed, int m) {

		if (m > seed - m)
			m = seed - m;
		int b = 1;
		/*@
		    loop invariant 1 <= r <= m + 1;
		    loop invariant b >= 1;
		    loop assigns r, b;
		    loop variant m - r + 1;
		*/
		for (int r = 1; r <= m; r++) {
			b = b * (seed - r + 1) / r;
		}
		return b;
}
