
#include <limits.h>

/*@ logic integer foo312_inner(integer i, integer c, integer d, integer center) =
      c > d ? 0 :
      ((i*i + c*c) <= center ? 1 : 0) + foo312_inner(i, c+1, d, center);
*/

/*@ logic integer foo312_count_i(integer count, integer d) =
      d <= 0 ? 0 :
      foo312_inner(d, 1, d, (2*count)*(2*count)) + foo312_count_i(count, d-1);
*/

/*@
  requires 0 <= count;
  requires 2 * count <= INT_MAX;
  requires (2 * count) * (2 * count) <= INT_MAX;
  assigns \nothing;
  ensures 0 <= \result;
  ensures \result <= INT_MAX;
  ensures count == 0 ==> \result >= 0;
  ensures count > 0 ==> \result >= 0;
  ensures \true;
*/
int foo312(int count) {

		int ret = 0;
		int diameter = 2 * count;
		int center = diameter * diameter;
		
        /*@
          loop invariant diameter == 2 * count;
          loop invariant center == diameter * diameter;
          loop invariant ret >= 0;
          loop invariant 1 <= i && i <= 2 * count + 1;
          loop invariant (i <= 2 * \at(count,Pre)) ==> \true;
          loop invariant (i <= 2 * \at(count,Pre)) ==> (ret >= 0);
          loop assigns i, ret;
        */
        for (int i = 1; i <= 2 * count; i++) {
			
            /*@
              loop invariant 1 <= c && c <= 2 * count + 1;
              loop invariant ret >= 0;
              loop invariant diameter == 2 * count;
              loop invariant center == diameter * diameter;
              loop invariant 1 <= i && i <= 2 * count;
            */
            for (int c = 1; c <= 2 * count; c++) {
				int diagnalLengthSquare = (i * i + c * c);
				if (diagnalLengthSquare <= center) {
					ret++;
				}
			}
            
		}
            
		return ret;
}
