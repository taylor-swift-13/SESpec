/*@ 
  logic integer next_digit_quotient(integer n, integer c) = (10*n)/c;
  logic integer next_remainder(integer n, integer c) = (10*n)%c;

  logic integer nth_digit(integer n, integer c, integer r) = 
    r <= 0 ? 0 : (r == 1 ? next_digit_quotient(n,c) : nth_digit(next_remainder(n,c), c, r-1));
*/

/*@ 
  requires c != 0;
  assigns \nothing;
  ensures \result == nth_digit(\old(num), \old(c), \old(r));
*/
int findNthDigit(int num, int c, int r);

int findNthDigit(int num, int c, int r) {
		int result = 0;
		/*@
		  loop invariant c == \at(c, Pre);
		  loop invariant ((r == 0) ? result : nth_digit(num, c, r)) == nth_digit(\at(num, Pre), \at(c, Pre), \at(r, Pre));
		  loop assigns num, result, r;
		  loop variant (r >= 0 ? r : 0);
		*/
		while (r > 0) {
			r -= 1;
			num *= 10;
			result = num / c;
			num %= c;
			//@ assert \abs(num) < \abs(c);
		}
		return result;
}
