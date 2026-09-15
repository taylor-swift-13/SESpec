#include <limits.h>


/*@
  predicate cube_progress(integer k0, integer c, integer x, integer y) =
    x == c * c * c && y == c && c <= k0;
*/

/*@loop invariant (0 < \at(k,Pre)) ==> (y == c);
      loop invariant (0 < \at(k,Pre)) ==> (0 <= c <= k);
      loop invariant (0 < \at(k,Pre)) ==> (k == \at(k,Pre));
      loop invariant (!(0 < \at(k,Pre))) ==> ((c == 0)&&(x == 0)&&(y == 0)&&(k == \at(k,Pre)));
      loop invariant k == \at(k,Pre);
      loop assigns c, y, x;*/
void stub_A(int k);

/*@loop invariant y*y*y <= x;
    loop invariant y == c;
    loop invariant x == y*y*y*x || x >= 0;
    loop invariant x == y*y*y - y;
    loop invariant x == y*y*y + x - y*y*y;
    loop invariant x == y*y*y * c;
    loop invariant x == y * y * y + x - (y * y * y);
    loop invariant x == c * c * c;
    loop invariant c <= k;
    loop invariant 0 <= x;
    loop invariant 0 <= c;
    loop assigns y;
    loop assigns x;
    loop assigns c;*/
void stub_B(int k);

/*@loop invariant y*y*y <= x;
    loop invariant y == c;
    loop invariant x == y*y*y*x || x >= 0;
    loop invariant x == y*y*y - y;
    loop invariant x == y*y*y + x - y*y*y;
    loop invariant x == y*y*y * c;
    loop invariant x == y * y * y + x - (y * y * y);
    loop invariant x == c * c * c;
    loop invariant c <= k;
    loop invariant 0 <= x;
    loop invariant 0 <= c;
    loop assigns y;
    loop assigns x;
    loop assigns c;*/
void check_A_implies_B(int k) {
    stub_A(k);
}

/*@loop invariant (0 < \at(k,Pre)) ==> (y == c);
      loop invariant (0 < \at(k,Pre)) ==> (0 <= c <= k);
      loop invariant (0 < \at(k,Pre)) ==> (k == \at(k,Pre));
      loop invariant (!(0 < \at(k,Pre))) ==> ((c == 0)&&(x == 0)&&(y == 0)&&(k == \at(k,Pre)));
      loop invariant k == \at(k,Pre);
      loop assigns c, y, x;*/
void check_B_implies_A(int k) {
    stub_B(k);
}
