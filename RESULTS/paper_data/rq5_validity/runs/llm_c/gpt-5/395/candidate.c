/*@ 
  logic integer sum4(integer n) = (n <= 0) ? 0 : n*n*n*n + sum4(n-1);
*/

/*@ 
  requires p <= 58;
  assigns \nothing;
  ensures \result == 16 * sum4(p);
  ensures \result >= 0;
*/
int evenPowerSum(int p);

int evenPowerSum(int p) {

		int odd = 0;
		/*@
		  loop invariant c >= 1;
		  loop invariant p <= 58;
		  loop invariant odd == 16 * sum4(c-1);
		  loop invariant odd >= 0;
		  loop assigns odd, c;
		  loop variant p - c + 1;
		*/
		for (int c = 1; c <= p; c++) {
			int tmp = 2 * c;
			odd = odd + (tmp * tmp * tmp * tmp);
		}
		return odd;
}
