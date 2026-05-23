
#include <limits.h>

/*@
  logic integer power10(integer e) =
    e <= 0 ? 1 : 10 * power10(e - 1);
*/

/*@
  requires \true;
  assigns \nothing;
  ensures (\at(r,Pre) <= 0) ==> (\result == 0 &&
                                 r == \at(r,Pre) &&
                                 c == \at(c,Pre) &&
                                 num == \at(num,Pre));
*/
int foo303_c387(int num, int c, int r) {

		int ret = 0;
		
            
        /*@
          loop invariant (!(\at(r,Pre) > 0)) ==> ((ret == 0)&&(r == \at(r,Pre))&&(c == \at(c,Pre))&&(num == \at(num,Pre)));
          loop invariant c == \at(c,Pre);
          loop assigns r, num, ret;
        */
            while (r > 0) {
			r -= 1;
			num *= 10;
			ret = num / c;
			num %= c;
		}
            
		return ret;
}
