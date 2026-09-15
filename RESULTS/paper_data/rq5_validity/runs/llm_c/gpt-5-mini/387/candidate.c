#include <limits.h>

int findNthDigit(int num, int c, int r);

/*@
    requires c > 0;
    requires 0 <= num < c;
    requires r >= 0;
    requires c <= (INT_MAX + 10) / 10;
    assigns \nothing;
    ensures \old(r) == 0 ==> \result == 0;
    ensures \old(r) > 0 ==> 0 <= \result <= 9;
*/
int findNthDigit(int num, int c, int r) {

		int ret = 0;
		/*@
		    loop invariant 0 <= r <= \old(r);
		    loop invariant 0 <= num < c;
		    loop invariant 0 <= ret <= 9;
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
