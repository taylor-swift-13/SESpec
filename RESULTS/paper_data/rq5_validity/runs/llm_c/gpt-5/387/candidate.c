/*@ 
  logic integer pow10(integer n) = (n <= 0) ? 1 : 10 * pow10(n - 1);
*/

int findNthDigit(int num, int c, int r);

/*@ 
  requires c > 0;
  requires r >= 0;
  requires 0 <= num < c;

  assigns \nothing;

  ensures 0 <= \result && \result < 10;
  ensures \result == (((pow10(\old(r)) * \old(num)) / \old(c)) % 10);
*/
int findNthDigit(int num, int c, int r) {

		int ret = 0;
		/*@
		  loop invariant c > 0;
		  loop invariant r >= 0;
		  loop invariant 0 <= num < c;
		  loop invariant 0 <= ret && ret < 10;
		  loop assigns r, num, ret;
		  loop variant r;
		*/
		while (r > 0) {
			r -= 1;
			num *= 10;
			ret = num / c;
			num %= c;
		}
		return ret;
}
