
#include <stddef.h>

/*@ 
  predicate undef_data_at{L}(int *p) = \true;
*/

void foo53() {

    int x;
    int y;

    x = 0;

    /*@
      loop invariant x % 5 == 0;
      loop invariant x <= 105;
      loop assigns x;
    */
    while (x < 99) {
       if (y % 2 == 0)
       x += 10;
       else
       x -= 5;
    }
}
