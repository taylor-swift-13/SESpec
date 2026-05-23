
#include <limits.h>


void foo55(unsigned int y) {

    unsigned int x;

    x = 2;

    /*@
      loop invariant 2 <= x;
      loop invariant (y < 2) || (x <= y);
      loop invariant x >= 2;
      loop invariant y == \at(y,Pre);
      loop invariant x == 2 || x > 2;
      loop invariant (x < y) ==> (x < y + 1);
      loop invariant (2 < \at(y,Pre)) ==> (x <= \at(y,Pre));
      loop invariant (2 < \at(y,Pre)) ==> (x <= y);
      loop invariant (2 < \at(y,Pre)) ==> (x >= 2);
      loop invariant (!(2 < \at(y,Pre))) ==> ((x == 2)&&(y == \at(y,Pre)));
      loop invariant y == \at(y,Pre);
      loop assigns x;
    */
    while (x < y) {
        if (x < y / x) {
            x *= x;
        }
        else {
            x++;
        }
    }
}
