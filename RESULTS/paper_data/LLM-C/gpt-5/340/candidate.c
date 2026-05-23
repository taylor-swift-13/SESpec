int findDivisor(int n, int z);

/*@
  assigns \nothing;
  ensures 0 <= \result <= \abs(\old(z));
  ensures \result == (\abs(\old(z)) == 0 ? 0 : \sum_{integer d=1..(\abs(\old(z)))} ((n % d == 0) ? 1 : 0));
*/
int findDivisor(int n, int z) {

		if (z < 0) {
			z = -z;
		}
		/*@ assert z >= 0; */

		int result = 0;
		/*@
			loop invariant z >= 0;
			loop invariant 1 <= loop <= z + 1;
			loop invariant 0 <= result <= loop - 1;
			loop invariant result == (\sum_{integer d=1..(loop-1)} ((n % d == 0) ? 1 : 0));
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
