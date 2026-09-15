
#include <limits.h>

/*@
  logic integer power(integer base, integer exp) =
    exp <= 0 ? 1 : base * power(base, exp - 1);
*/

int foo388(int num, int c, int r) {

		int result = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@

          loop invariant (\at(r,Pre) > 0) ==> (r >= 0);
          loop invariant (\at(r,Pre) > 0) ==> (r <= \at(r,Pre));
          loop invariant (\at(r,Pre) > 0) ==> (\at(r,Pre) - r >= 0);

          loop invariant (\at(r,Pre) > 0) ==> (\at(r,Pre) - r <= \at(r,Pre));

          loop invariant (\at(r,Pre) > 0) ==> (r == 0 ==> (\at(r,Pre) - r == \at(r,Pre)));

          loop invariant (\at(r,Pre) > 0) ==> (0 <= r && r <= \at(r,Pre));
          loop invariant (\at(r,Pre) > 0) ==> (r >= 0);
          loop invariant (\at(r,Pre) > 0) ==> (r <= \at(r,Pre));

          loop invariant (\at(r,Pre) > 0) ==> (c == \at(c,Pre));

          loop invariant (\at(r,Pre) > 0) ==> (((result == 0)&&(r == \at(r,Pre))&&(c == \at(c,Pre))&&(num == \at(num,Pre))) || ((r < \at(r,Pre))));

          loop invariant (!(\at(r,Pre) > 0)) ==> ((result == 0)&&(r == \at(r,Pre))&&(c == \at(c,Pre))&&(num == \at(num,Pre)));
          loop invariant c == \at(c,Pre);
          loop assigns r, num, result;
            */
            while (r > 0) {
			r -= 1;
			num *= 10;
			result = num / c;
			num %= c;
		}
            
		return result;
}
