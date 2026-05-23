/*@
    requires z >= 0;
    requires num >= 0 || z > 0;
    assigns \nothing;
    ensures \result >= 0;
    ensures \result == (\numof integer index; 1 <= index <= z && num % index == 0);
*/
int findDivisor(int num, int z) {

		if (z < 0) {
			z = -z;
		}
		int result = 0;
		/*@
		    loop invariant 1 <= index <= z + 1;
		    loop invariant 0 <= result <= index - 1;
		    loop invariant result == (\numof integer k; 1 <= k < index && num % k == 0);
		    loop assigns index, result;
		    loop variant z - index + 1;
		*/
		for (int index = 1; index <= z; index++) {
			if (num % index == 0) {
				result = result + 1;
			}
		}
		return result;
}
