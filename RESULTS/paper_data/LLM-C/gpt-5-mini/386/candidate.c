int findNthDigit(int num, int b, int r);

/*@
    requires b > 0;
    requires r >= 0;
    requires num >= 0;
    assigns \nothing;
    ensures 0 <= \result <= 9;
    ensures \result == ((\at(num,Pre) * \pow(10,\at(r,Pre)) / b) % 10);
*/
int findNthDigit(int num, int b, int r) {

		int result = 0;
		/*@
		    loop invariant r >= 0;
		    loop invariant 0 <= result <= 9;
		    loop invariant \exists integer k, q;
		        k == \at(r,Pre) - r &&
		        k >= 0 &&
		        \at(num,Pre) * \pow(10,k) == b * q + num &&
		        ((k == 0) ==> result == 0) &&
		        ((k >= 1) ==> result == q % 10);
		    loop assigns r, num, result;
		    loop variant r;
		*/
		while (r > 0) {
			r -= 1;
			num *= 10;
			result = num / b;
			num %= b;
		}
		return result;
}
