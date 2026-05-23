/*@ axiomatic MathDefs {
  logic integer fact(integer n);
  axiom fact0: fact(0) == 1;
  axiom fact_pos: \forall integer n; n >= 1 ==> fact(n) == n * fact(n - 1);

  logic integer pow10(integer n);
  axiom pow10_0: pow10(0) == 1;
  axiom pow10_step: \forall integer n; n >= 0 ==> pow10(n + 1) == 10 * pow10(n);
} */

int firstDigit(int number);

/*@ 
  requires number >= 0;
  requires number <= 12;
  assigns \nothing;
  ensures \exists integer k; pow10(k) <= fact(number) < pow10(k+1) && \result == fact(number) / pow10(k);
  ensures 1 <= \result <= 9;
*/
int firstDigit(int number) {

		int first = 1;
		/*@ 
		  loop invariant 2 <= c <= number + 1;
		  loop invariant first == fact(c - 1);
		  loop assigns first, c;
		  loop variant number - c + 1;
		*/
		for (int c = 2; c <= number; c++) {
			first *= c;
		}
		/*@ assert first == fact(number); */
		/*@ ghost int init_first = first; */
		int result = 0;
		/*@
		  loop invariant first >= 0;
		  loop invariant 0 <= result <= 9;
		  loop invariant \exists integer k, r; 
		                   k >= 0 && 0 <= r < pow10(k) && init_first == first * pow10(k) + r;
		  loop assigns first, result;
		  loop variant first;
		*/
		while (first > 0) {
			result = first % 10;
			first /= 10;
		}
		return result;
}
