
#include <limits.h>

/*@ logic integer power(integer b, integer e) =
      e <= 0 ? 1 : b * power(b, e - 1);
*/

/*@
  assigns \nothing;

  ensures (\old(r) <= 0) ==> (\result == 0);

  ensures \true;

  ensures \true;

  ensures \true;

  ensures \true;
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
