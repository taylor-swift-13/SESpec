/*@ 
  logic integer fact(integer n) = (n <= 1) ? 1 : n * fact(n - 1);
*/

int lastTwoDigits(int num);

/*@
  assigns \nothing;

  behavior safe:
    assumes num <= 12;
    ensures \result == fact(num) % 100;
    ensures 0 <= \result < 100;

  behavior other:
    assumes num > 12;

  complete behaviors;
  disjoint behaviors;
*/
int lastTwoDigits(int num) {

		int ret = 1;
		/*@
		  loop invariant 1 <= loop <= num + 1;
		  loop invariant num <= 12 ==> ret == fact(loop - 1);
		  loop assigns ret, loop;
		  loop variant num - loop + 1;
		*/
		for (int loop = 1; loop <= num; loop++) {
			ret *= loop;
		}
		int result = (int) (ret % 100);
		return result;
}
