int binomialCoeff(int num, int p);

/*@
  logic integer prod(integer a, integer b) =
    a > b ? 1 : a * prod(a+1, b);

  requires 0 <= num;
  requires 0 <= \old(p) <= num;
  assigns \nothing;
  ensures \result * prod(1, \old(p)) == prod(num - \old(p) + 1, num);
  ensures \result >= 1;
*/
int binomialCoeff(int num, int p) {

		if (p > num - p)
			p = num - p;
		int b = 1;
		/*@
		  loop invariant 1 <= r <= p + 1;
		  loop invariant b * prod(1, r-1) == prod(num - r + 2, num);
		  loop assigns r, b;
		  loop variant p - r + 1;
		*/
		for (int r = 1; r <= p; r++) {
			b = b * (num - r + 1) / r;
		}
		return b;
}
