
#include <limits.h>

/*@
  predicate is_pos(int x) = x > 0;
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

        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant is_pos(num1) && is_pos(num2);
          loop invariant result >= num1 && result >= num2;
          loop invariant result > 0;
          loop invariant \forall integer k; (num1 <= k < result) ==> (k % num1 != 0 || k % num2 != 0);
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
