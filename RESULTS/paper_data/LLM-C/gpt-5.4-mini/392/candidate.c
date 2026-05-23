/*@
    requires num >= 0;
    assigns \nothing;
    ensures 0 <= \result < 100;
*/
int lastTwoDigits(int num);

 /*@
    requires num >= 0;
    assigns \nothing;
    ensures 0 <= \result < 100;
*/
int lastTwoDigits(int num) {

		int ret = 1;
		/*@
		    loop invariant 1 <= number <= num + 1;
		    loop invariant ret >= 1;
		    loop assigns number, ret;
		    loop variant num - number + 1;
		*/
		for (int number = 1; number <= num; number++) {
			ret *= number;
		}
		int result = (int) (ret % 100);
		return result;
}
