int countDigit(int number);

/*@
    requires \true;
    assigns \nothing;
    ensures \result >= 0;
    ensures number <= 0 <==> \result == 0;
    ensures number > 0 ==> \result >= 1;
*/
int countDigit(int number) {

		int ret = 0;
		/*@
		    loop invariant number >= 0;
		    loop invariant ret >= 0;
		    loop assigns number, ret;
		    loop variant number;
		*/
		while (number > 0) {
			number /= 10;
			ret++;
		}
		return ret;
}
