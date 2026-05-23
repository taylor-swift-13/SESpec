int findDivisor(int num, int z);

/*@
    requires z != INT_MIN;
    assigns \nothing;
    ensures 0 <= \result <= \abs(\at(z,Pre));
    ensures \result == (\sum integer i; 1 <= i <= \abs(\at(z,Pre)); ((\at(num,Pre) % i) == 0) ? 1 : 0);
*/
int findDivisor(int num, int z) {

		if (z < 0) {
			z = -z;
		}
		int result = 0;
		/*@
		    loop invariant 1 <= index <= z + 1;
		    loop invariant 0 <= result <= index-1;
		    loop invariant result == (\sum integer j; 1 <= j <= index-1; ((num % j) == 0) ? 1 : 0);
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
