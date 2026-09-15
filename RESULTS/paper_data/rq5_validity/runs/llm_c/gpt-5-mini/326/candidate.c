/*@
  logic integer fact(integer n) =
    (n <= 1 ? 1 : n * fact(n-1));
*/

/*@
    requires 0 <= num <= 12;
    assigns \nothing;
    ensures 0 <= \result <= 9;
    ensures \result == fact(num) % 10;
*/
int firstDigit(int num);

int firstDigit(int num) {

		int first = 1;
		/*@
		  loop invariant (2 <= c && c <= num+1) || (num < 2 && c == 2);
		  loop invariant first == fact(c-1);
		  loop assigns c, first;
		  loop variant num - c + 2;
		*/
		for (int c = 2; c <= num; c++) {
			first *= c;
		}
		int result = 0;
		/*@
		  loop invariant first >= 0;
		  loop invariant 0 <= result <= 9;
		  loop assigns first, result;
		  loop variant first;
		*/
		while (first > 0) {
			result = first % 10;
			first /= 10;
		}
		return result;
}
