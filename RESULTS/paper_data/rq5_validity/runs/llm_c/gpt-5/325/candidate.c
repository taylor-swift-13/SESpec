/*@ axiomatic Factorial {
      logic integer fact(integer n);
      axiom fact0: fact(0) == 1;
      axiom fact_pos: \forall integer n; n >= 1 ==> fact(n) == n * fact(n-1);
  }

  axiomatic MSD {
      logic integer msd(integer n);
      axiom msd_pos:  \forall integer n; n > 0 ==> 1 <= msd(n) <= 9;
      axiom msd_base: \forall integer n; 0 < n < 10 ==> msd(n) == n;
      axiom msd_rec:  \forall integer n; n >= 10 ==> msd(n) == msd(n/10);
  }

  requires num >= 0;
  requires fact(num) <= 2147483647;
  assigns \nothing;
  ensures 1 <= \result <= 9;
  ensures \result == msd(fact(num));
*/
int firstDigit(int num);

int firstDigit(int num) {

		int first = 1;
		/*@
		  loop invariant j >= 2 && j <= num + 1;
		  loop invariant first == fact(j-1);
		  loop assigns first, j;
		  loop variant num - j + 1;
		*/
		for (int j = 2; j <= num; j++) {
			first *= j;
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
