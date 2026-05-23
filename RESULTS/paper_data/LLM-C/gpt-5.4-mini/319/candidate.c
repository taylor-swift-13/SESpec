/*@
    requires n >= 0;
    requires y >= 0;
    assigns \nothing;
    ensures \result >= 0;
*/
int lcm(int n, int y);

 /*@
    requires n >= 0;
    requires y >= 0;
    assigns \nothing;
    ensures \result >= 0;
*/
int lcm(int n, int y) {

		int ret = 1;
		int l = 1;
		if (n > y) {
			int g = n;
			n = y;
			y = g;
		}
		/*@
		    loop invariant 1 <= j <= n + 1;
		    loop invariant ret >= 1;
		    loop invariant \forall integer k; 1 <= k < j ==> !(n % k == 0 && y % k == 0) || ret >= k;
		    loop assigns j, ret;
		    loop variant n - j + 1;
		*/
		for (int j = 1; j <= n; j++) {
			if (n % j == 0 && y % j == 0) {
				ret = j;
			}
		}
		l = (n * y) / ret;
		return l;
}
