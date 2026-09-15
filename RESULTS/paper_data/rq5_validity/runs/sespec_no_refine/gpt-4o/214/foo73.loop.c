
#include <stdbool.h>

/*@
  logic boolean is_power_of_4(integer x) = 
    x > 0 && (\exists integer k; x == \pow(4, k));
*/

/*@
  requires n > 0;
  ensures \result == 1 ==> is_power_of_4(n);
  ensures \result != 1 ==> !is_power_of_4(n);
*/
int foo73(int n) {

    if (n <= 0) {
        return 0;
    }

    /*@
      loop invariant n > 0;
      loop invariant is_power_of_4(n) || !(n % 4 == 0);
      loop assigns n;
    */
    while (n % 4 == 0) {
        n /= 4;
    }

    return n == 1;
}
