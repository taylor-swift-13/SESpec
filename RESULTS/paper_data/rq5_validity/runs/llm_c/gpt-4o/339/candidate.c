/*@
    requires z != 0;
    ensures \result >= 0;
    ensures \result == \sum(1 <= i <= \abs(z), (num % i == 0 ? 1 : 0));
*/
int findDivisor(int num, int z);

int findDivisor(int num, int z) {

		if (z < 0) {
			z = -z;
		}
		int result = 0;
		/*@
		    loop invariant 1 <= index <= z + 1;
		    loop invariant result == \sum(1 <= i < index, (num % i == 0 ? 1 : 0));
		    loop assigns index, result;
		    loop variant z - index;
		*/
		for (int index = 1; index <= z; index++) {
			if (num % index == 0) {
				result = result + 1;
			}
		}
		return result;
}
