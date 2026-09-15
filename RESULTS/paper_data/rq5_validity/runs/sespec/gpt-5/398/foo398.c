
#include <limits.h>

/*@
  logic integer power(integer base, integer exp) =
    exp <= 0 ? 1 : base * power(base, exp - 1);
*/

/*@
  requires number >= 0;
  assigns \nothing;
  ensures \result >= 0;
  ensures number == \old(number);
  ensures (\old(number) == 0) ==> (\result == 0);
  ensures (\old(number) > 0) ==> (\result >= 1);
  ensures (\old(number) > 0) ==> (\old(number) < power(10, \result));
  ensures \result == (\old(number) == 0 ? 0 : (\result));
*/
int foo398(int number) {

		int ret = 0;
		
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant ret >= 0;
          loop invariant number >= 0;
          loop invariant number <= \at(number,Pre);

          loop invariant power(10, ret) >= 1;

          loop invariant number * power(10, ret) <= \at(number,Pre);
          loop invariant \at(number,Pre) < (number + 1) * power(10, ret);

          loop invariant (number == 0) ==> (\at(number,Pre) < power(10, ret));
          loop invariant (\at(number,Pre) == 0) ==> (ret == 0);
          loop assigns number, ret;
            */
            while (number > 0) {
			number /= 10;
			ret++;
		}
            
		return ret;
}
