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
		int l = 1;
		if (n > y) {
			int g = n;
			n = y;
			y = g;
		}
		/*@
		    loop invariant 1 <= j <= n + 1;
		    loop invariant ret > 0;
		    loop invariant \forall integer k; 1 <= k < j ==> (n % k == 0 && y % k == 0) ==> ret >= k;
		    loop assigns j, ret;
		    loop variant n - j;
		*/
		for (int j = 1; j <= n; j++) {
			if (n % j == 0 && y % j == 0) {
				ret = j;
			}
		}
		l = (n * y) / ret;
		return l;
}
