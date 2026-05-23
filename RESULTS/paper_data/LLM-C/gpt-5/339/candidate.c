/*@ 
  logic integer count_divisors(integer num, integer z) =
    z <= 0 ? 0 : count_divisors(num, z - 1) + (num % z == 0 ? 1 : 0);
*/

/*@ 
  requires \true;
  assigns \nothing;
  ensures \result == count_divisors(num, \abs(\old(z)));
  ensures 0 <= \result <= \abs(\old(z));
*/
int findDivisor(int num, int z);

int findDivisor(int num, int z) {

		if (z < 0) {
			z = -z;
		}
		int result = 0;
		/*@
		  loop invariant z >= 0;
		  loop invariant z == \abs(\at(z,Pre));
		  loop invariant 1 <= index <= z + 1;
		  loop invariant 0 <= result <= index - 1;
		  loop invariant result == count_divisors(num, index - 1);
		  loop assigns result, index;
		  loop variant z - index + 1;
		*/
		for (int index = 1; index <= z; index++) {
			if (num % index == 0) {
				result = result + 1;
			}
		}
		return result;
}
