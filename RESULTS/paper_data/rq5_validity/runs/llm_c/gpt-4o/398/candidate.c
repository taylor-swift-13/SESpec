/*@ 
    requires number >= 0;
    ensures \result >= 0;
    ensures \result == 0 <==> number == 0;
    ensures \result > 0 ==> \result == \floor(\log10(number)) + 1;
    assigns \nothing;
*/
int countDigit(int number);

int countDigit(int number) {

		int ret = 0;
		/*@
		loop invariant number >= 0;
		loop invariant ret >= 0;
		loop invariant \pow(10, ret) <= \old(number) < \pow(10, ret + 1);
		loop assigns number, ret;
		loop variant number;
		*/
		while (number > 0) {
			number /= 10;
			ret++;
		}
		return ret;
}
