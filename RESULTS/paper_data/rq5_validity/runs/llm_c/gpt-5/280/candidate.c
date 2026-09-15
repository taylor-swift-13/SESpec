/*@ 
  logic integer pos_divisors_upto(integer n, integer t) =
    (t <= 0 || n <= 0) ? 0 :
    pos_divisors_upto(n, t - 1) + ((n % t == 0) ? 1 : 0);

  logic integer pos_divisors(integer n) = (n <= 0) ? 0 : pos_divisors_upto(n, n);

  predicate is_positive_square(integer n) =
    n > 0 && (\exists integer k; k >= 1 && k * k == n);
*/

const char * countDivisors(int number);

/*@
  requires \true;
  assigns \nothing;

  ensures number <= 0 ==> \result == "Even";

  ensures number > 0 && is_positive_square(number) ==> \result == "Odd";
  ensures number > 0 && !is_positive_square(number) ==> \result == "Even";

  ensures \result == "Even" || \result == "Odd";
*/
const char * countDivisors(int number) {

		int result = 0;
		/*@
		  loop invariant number <= 0 ==> (c == 1 && result == 0);
		  loop invariant number > 0 ==> 1 <= c <= number + 1;
		  loop invariant number > 0 ==> 0 <= result <= c - 1;
		  loop invariant number > 0 ==> result == pos_divisors_upto(number, c - 1);
		  loop assigns c, result;
		  loop variant number - c + 1;
		*/
		for (int c = 1; c <= number; c++) {
			if (number % c == 0) {
				result++;
			}
		}
		/*@ assert number <= 0 ==> result == 0; */
		/*@ assert number > 0 ==> result == pos_divisors(number); */
		if (result % 2 == 0) {
			return "Even";
		} else {
			return "Odd";
		}
}
