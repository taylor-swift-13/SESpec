/*@
    requires z != 0;
    ensures \result >= 0;
    ensures \result == \sum(1, z, \lambda integer i; (n % i == 0 ? 1 : 0));
*/
int findDivisor(int n, int z);

int findDivisor(int n, int z) {

		if (z < 0) {
			z = -z;
		}
		int result = 0;
		/*@
		    loop invariant 1 <= loop <= z + 1;
		    loop invariant result == \sum(1, loop - 1, \lambda integer i; (n % i == 0 ? 1 : 0));
		    loop assigns loop, result;
		    loop variant z - loop;
		*/
		for (int loop = 1; loop <= z; loop++) {
			if (n % loop == 0) {
				result = result + 1;
			}
		}
		return result;
}
