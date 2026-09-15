/*@
    requires z >= 0;
    assigns \nothing;
    ensures \result >= 0;
    ensures \result <= z;
    ensures \result == (\numof integer i; 1 <= i <= z && num % i == 0);
*/
int findDivisor(int num, int z);

int findDivisor(int num, int z) {
		if (z < 0) {
			z = -z;
		}
		int result = 0;
		/*@
		    loop invariant 1 <= loop <= z + 1;
		    loop invariant 0 <= result <= loop - 1;
		    loop invariant result == (\numof integer i; 1 <= i < loop && num % i == 0);
		    loop assigns loop, result;
		    loop variant z - loop + 1;
		*/
		for (int loop = 1; loop <= z; loop++) {
			if (num % loop == 0) {
				result = result + 1;
			}
		}
		return result;
}
