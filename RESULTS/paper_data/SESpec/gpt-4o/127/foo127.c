
#include <limits.h>

/*@
  requires num1 > 0 && num2 > 0;
  assigns \nothing;
  ensures \result == -1 || (\result % \old(num1) == 0 && \result % \old(num2) == 0);
  ensures \result == -1 ==> \forall integer k; (\old(num1) > \old(num2) ? \old(num1) : \old(num2)) <= k <= INT_MAX ==> (k % \old(num1) != 0 || k % \old(num2) != 0);
  ensures \result != -1 ==> \result >= (\old(num1) > \old(num2) ? \old(num1) : \old(num2)) && \result <= INT_MAX;
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
      loop invariant result >= (\at(num1, Pre) > \at(num2, Pre) ? \at(num1, Pre) : \at(num2, Pre));
      loop invariant \forall integer k; (\at(num1, Pre) > \at(num2, Pre) ? \at(num1, Pre) : \at(num2, Pre)) <= k < result ==> (k % \at(num1, Pre) != 0 || k % \at(num2, Pre) != 0);
      loop invariant result <= INT_MAX;
      loop assigns result;
      loop variant INT_MAX - result;
    */
    while (result < INT_MAX) {
        if (result % num1 == 0 && result % num2 == 0) {
            break;
        }
        result++;
    }

    if (result % num1 == 0 && result % num2 == 0) {
        return result;
    }
    return -1;
}
