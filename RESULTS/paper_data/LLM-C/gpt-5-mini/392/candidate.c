int lastTwoDigits(int num);

/*@
    requires 0 <= num <= 12;
    assigns \nothing;
    ensures 0 <= \result < 100;
    ensures \result == (\product integer i; 1 <= i <= num; i) % 100;
*/
int lastTwoDigits(int num) {

		int ret = 1;
		/*@
		  loop invariant 1 <= number <= num + 1;
		  loop invariant ret == (\product integer i; 1 <= i < number; i);
		  loop assigns number, ret;
		  loop variant num - number + 1;
		*/
		for (int number = 1; number <= num; number++) {
			ret *= number;
		}
		int result = (int) (ret % 100);
		return result;
}
