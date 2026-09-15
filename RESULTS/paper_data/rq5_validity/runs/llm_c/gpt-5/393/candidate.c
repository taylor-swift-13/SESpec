int lastTwoDigits(int num);

/*@ logic integer fact(integer n) = n <= 1 ? 1 : n * fact(n-1); */

/*@
  assigns \result \from num;

  behavior negative:
    assumes num < 0;
    ensures \result == 1;

  behavior small_nonneg:
    assumes 0 <= num <= 12;
    ensures \result == fact(num) % 100;
    ensures 0 <= \result < 100;

  complete behaviors negative, small_nonneg;
  disjoint behaviors negative, small_nonneg;
*/
int lastTwoDigits(int num) {

		int ret = 1;
		/*@
		  loop invariant loop >= 1;
		  loop invariant (num >= 0) ==> (loop <= num + 1);
		  loop invariant (0 <= num <= 12) ==> (ret == fact(loop - 1));
		  loop invariant (0 <= num <= 12) ==> (ret >= 1);
		  loop assigns ret, loop;
		  loop variant num - loop + 1;
		*/
		for (int loop = 1; loop <= num; loop++) {
			ret *= loop;
		}
		int remainder = (int) (ret % 100);
		return remainder;
}
