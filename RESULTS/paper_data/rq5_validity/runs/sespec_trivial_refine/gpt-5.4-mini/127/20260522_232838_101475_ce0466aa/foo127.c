
#include <limits.h>

/*@ logic integer iabs(integer x) = x < 0 ? -x : x; */
/*@ predicate divides(integer a, integer b) = \exists integer k; b == a * k; */

/*@
  assigns \nothing;
  ensures (num1 == 0 || num2 == 0) ==> \result == -1;
  ensures \result != -1 ==> \result >= iabs(num1) && \result >= iabs(num2);
  ensures \result != -1 ==> \result <= INT_MAX;
*/
int foo127(int num1, int num2) {

        if (num1 == 0 || num2 == 0) {
            return -1;
        }
        if (num1 < 0)
            num1 = -num1;
        if (num2 < 0)
            num2 = -num2;

        int result = (num1 > num2) ? num1 : num2;

        /*@
          loop invariant result >= num1;
          loop invariant result >= num2;
          loop invariant result <= INT_MAX;
          loop assigns result;
        */
        while (result < INT_MAX)
        {
            if (result % num1 == 0 && result % num2 == 0)
            {
                break;
            }
            result++;
        }

        if (result % num1 == 0 && result % num2 == 0) {
            return result;
        }
        return -1;
}
