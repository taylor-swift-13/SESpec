int findDivisor(int num, int z);

/*@ 
  logic integer count_divisors_upto(integer n, integer up) =
    (up <= 0 ? 0 : \sum(integer d, 1, up, ((n % d) == 0) ? 1 : 0));
*/

/*@ 
  requires \true;
  assigns \nothing;
  ensures z == \abs(\at(z,Pre));
  ensures 0 <= \result <= \abs(\at(z,Pre));
  ensures \result == count_divisors_upto(num, \abs(\at(z,Pre)));
  behavior nonneg:
    assumes \at(z,Pre) >= 0;
    ensures z == \at(z,Pre);
    ensures \result == count_divisors_upto(num, \at(z,Pre));
  behavior neg:
    assumes \at(z,Pre) < 0;
    ensures z == -\at(z,Pre);
    ensures \result == count_divisors_upto(num, -\at(z,Pre));
  complete behaviors;
  disjoint behaviors;
*/
int findDivisor(int num, int z) {

		if (z < 0) {
			z = -z;
		}
		/*@ assert z == \abs(\at(z,Pre)); */
		/*@ assert z >= 0; */
		int result = 0;
		/*@
		  loop invariant z >= 0;
		  loop invariant 1 <= loop && loop <= z + 1;
		  loop invariant 0 <= result && result <= loop - 1;
		  loop invariant result == count_divisors_upto(num, loop - 1);
		  loop assigns result, loop;
		  loop variant z - loop;
		*/
		for (int loop = 1; loop <= z; loop++) {
			if (num % loop == 0) {
				result = result + 1;
			}
		}
		return result;
}
