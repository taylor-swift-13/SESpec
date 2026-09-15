#include <stddef.h>

/*@ 
  logic integer rem_after_steps(integer num, integer b, integer r) =
    (r <= 0 || b == 0) ? num :
    ((rem_after_steps(num, b, r-1) * 10) % b);

  logic integer quot_at_step(integer num, integer b, integer r) =
    (r <= 0 || b == 0) ? 0 :
    ((rem_after_steps(num, b, r-1) * 10) / b);
*/

/*@ 
  requires r >= 0;
  requires b != 0;
  assigns \nothing;
  ensures \result == quot_at_step(\old(num), \old(b), \old(r));
*/
int findNthDigit(int num, int b, int r);

int findNthDigit(int num, int b, int r) {
		int result = 0;
		/*@
		  loop invariant 0 <= (\at(r,Pre) - r) <= \at(r,Pre);
		  loop invariant b == \at(b,Pre);
		  loop invariant num == rem_after_steps(\at(num,Pre), \at(b,Pre), \at(r,Pre) - r);
		  loop invariant (\at(r,Pre) - r) == 0 ==> result == 0;
		  loop invariant (\at(r,Pre) - r) > 0  ==> result == quot_at_step(\at(num,Pre), \at(b,Pre), \at(r,Pre) - r);
		  loop assigns r, num, result;
		  loop variant r;
		*/
		while (r > 0) {
			r -= 1;
			num *= 10;
			result = num / b;
			num %= b;
		}
		return result;
}
