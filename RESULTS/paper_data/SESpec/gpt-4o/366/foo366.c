
#include <limits.h>

/*@
  requires n > 0; // Prevent division by zero
  requires n == \at(n, Pre);
  assigns \nothing;
  
*/
int foo366(int n) {
    int sum = 0;
    int count = 0;

    /*@
      loop invariant 1 <= i <= n + 1;
      loop invariant (count > 0) ==> (sum / count >= 0);
      loop invariant sum >= 0;
      loop invariant count >= 0;
      loop invariant n == \at(n, Pre);
      loop assigns i, sum, count;
    */
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0) {
            sum += i;
            count++;
        }
    }

    return sum / count;
}
