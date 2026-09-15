/*@
    requires z >= 0 || z < 0;
    assigns \nothing;
    ensures \result >= 0;
*/
int findDivisor(int n, int z);

 /*@
    assigns \nothing;
    ensures \result >= 0;
*/
int findDivisor(int n, int z) {

		if (z < 0) {
			z = -z;
		}
		int result = 0;
		/*@
            loop invariant 1 <= loop <= z + 1;
            loop invariant result >= 0;
            loop assigns loop, result;
            loop variant z - loop + 1;
        */
		for (int loop = 1; loop <= z; loop++) {
			if (n % loop == 0) {
				result = result + 1;
			}
		}
		return result;
}
