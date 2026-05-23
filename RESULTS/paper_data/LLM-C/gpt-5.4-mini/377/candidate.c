/*@
    requires p >= 0;
    requires seed >= 0;
    assigns \nothing;
    ensures \result >= 0;
    ensures p == 0 ==> \result == 1;
*/
int binomialCoeff(int seed, int p);

 /*@
    requires p >= 0;
    requires seed >= 0;
    assigns \nothing;
    ensures \result >= 0;
    ensures p == 0 ==> \result == 1;
*/
int binomialCoeff(int seed, int p) {

		if (p > seed - p)
			p = seed - p;
		int b = 1;
		/*@
		    loop invariant 1 <= r <= p + 1;
		    loop invariant b >= 1;
		    loop assigns r, b;
		    loop variant p - r + 1;
		*/
		for (int r = 1; r <= p; r++) {
			b = b * (seed - r + 1) / r;
		}
		return b;
}
