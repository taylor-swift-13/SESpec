/*@ logic integer count_divisors(integer n) =
      (n <= 0) ? 0 : \sum(integer d = 1; d <= n; d++) ((n % d == 0) ? 1 : 0);
*/

/*@
  requires \true;
  assigns \nothing;
  ensures \result == count_divisors(number);
  ensures \result >= 0;
  behavior nonpos:
    assumes number <= 0;
    ensures \result == 0;
  behavior pos:
    assumes number >= 1;
    ensures 1 <= \result <= number;
  complete behaviors;
  disjoint behaviors;
*/
int divisor(int number);

int divisor(int number) {

		int div = 0;
		/*@
		  loop invariant number >= 1 ==> 1 <= c <= number + 1;
		  loop invariant number >= 1 ==> 0 <= div <= c - 1;
		  loop invariant number >= 1 ==> div == \sum(integer d = 1; d <= c - 1; d++) ((number % d == 0) ? 1 : 0);
		  loop assigns c, div;
		  loop variant number - c + 1;
		*/
		for (int c = 1; c <= number; c++) {
			if (number % c == 0) {
				div++;
			}
		}
		return div;
}
