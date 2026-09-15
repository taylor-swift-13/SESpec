int lcm(int n, int y);

/*@
    requires n >= 0 && y >= 0;
    assigns \nothing;
    ensures \result >= 0;
    ensures (\old(n) == 0 || \old(y) == 0) ==> \result == 0;
    ensures (\old(n) != 0 && \old(y) != 0) ==>
        (\result % \old(n) == 0 && \result % \old(y) == 0 &&
         (\forall integer z; z >= 0 && z % \old(n) == 0 && z % \old(y) == 0 ==> z % \result == 0));
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
		    loop invariant 1 <= j <= n+1;
		    loop invariant 1 <= ret && ret <= n;
		    loop invariant n % ret == 0 && y % ret == 0;
		    loop invariant \forall integer k; 1 <= k < j ==> ((n % k == 0 && y % k == 0) ==> k <= ret);
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
