int findDivisor(int n, int z);

/*@
    requires \true;
    assigns \nothing;
    ensures \result >= 0;
    ensures \result == \numof integer i; 1 <= i <= (\old(z) >= 0 ? \old(z) : -\old(z)) && n % i == 0;
*/
int findDivisor(int n, int z) {

		if (z < 0) {
			z = -z;
		}
		int result = 0;
		/*@
		    loop invariant 1 <= loop <= z + 1;
		    loop invariant result >= 0;
		    loop invariant result == \numof integer j; 1 <= j < loop && n % j == 0;
		    loop assigns result, loop;
		    loop variant z - loop + 1;
		*/
		for (int loop = 1; loop <= z; loop++) {
			if (n % loop == 0) {
				result = result + 1;
			}
		}
		return result;
}
