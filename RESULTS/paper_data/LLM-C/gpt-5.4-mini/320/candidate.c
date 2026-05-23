/*@
    requires n > 0;
    requires y > 0;
    assigns \nothing;
    ensures \result > 0;
*/
int lcm(int n, int y);

 /*@
    requires n > 0;
    requires y > 0;
    assigns \nothing;
    ensures \result > 0;
*/
int lcm(int n, int y) {

		int ret = 1;
		int g = 1;
		/*@
		    loop invariant 1 <= l <= n + 1;
		    loop invariant ret >= 1;
		    loop assigns l, ret;
		    loop variant n - l + 1;
		*/
		if (n > y) {
			int r = n;
			n = y;
			y = r;
		}
		for (int l = 1; l <= n; l++) {
			if (n % l == 0 && y % l == 0) {
				ret = l;
			}
		}
		g = (n * y) / ret;
		return g;
}
