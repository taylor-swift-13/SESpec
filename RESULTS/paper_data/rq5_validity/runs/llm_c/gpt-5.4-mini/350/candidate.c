/*@
    requires num >= 0;
    assigns \nothing;
    ensures \result == (num ^ (
        (\let int result = 0;
         \let int ret = 0;
         \let int total = num;
         0)
    ));
*/
int evenBitToggleNumber(int num);

#include <limits.h>

/*@ 
    requires num >= 0;
    assigns \nothing;
    ensures \result >= 0;
*/
int evenBitToggleNumber(int num) {

		int result = 0;
		int ret = 0;
		int total = num;
		/*@
		    loop invariant total >= 0;
		    loop invariant ret >= 0;
		    loop invariant result >= 0;
		    loop invariant total <= num;
		    loop assigns result, ret, total;
		    loop variant total;
		*/
		while (total > 0) {
			if (ret % 2 == 0) {
				result = result | (1 << ret);
			}
			ret++;
			total >>= 1;
		}
		return num ^ result;
}
