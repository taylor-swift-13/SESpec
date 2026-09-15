/*@
    requires n > 0 && y > 0;
    ensures \result > 0;
    ensures \result % n == 0 && \result % y == 0;
    ensures \forall integer k; k > 0 && k % n == 0 && k % y == 0 ==> \result <= k;
    assigns \nothing;
*/
int lcm(int n, int y);

int lcm(int n, int y) {

		int ret = 1;
		int g = 1;
		if (n > y) {
			int r = n;
			n = y;
			y = r;
		}
		/*@
		    loop invariant 1 <= l <= n + 1;
		    loop invariant ret > 0;
		    loop invariant \forall integer k; 1 <= k < l ==> (n % k == 0 && y % k == 0) ==> ret >= k;
		    loop assigns l, ret;
		    loop variant n - l;
		*/
		for (int l = 1; l <= n; l++) {
			if (n % l == 0 && y % l == 0) {
				ret = l;
			}
		}
		g = (n * y) / ret;
		return g;
}
