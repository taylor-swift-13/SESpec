#include <limits.h>


/*@
  predicate foo86_y(integer kpre, integer c, integer y) = y == c;
  predicate foo86_x(integer kpre, integer c, integer x) = x == c * (c + 1) * (2 * c + 1) / 6;
  predicate foo86_c(integer kpre, integer c) = c >= 0;
  predicate foo86_goal(integer kpre, integer c, integer x, integer y) = x >= y * y;
*/

/*@loop invariant (0 < \at(k,Pre)) ==> (foo86_goal(\at(k,Pre), c, x, y));
          loop invariant (0 < \at(k,Pre)) ==> (foo86_y(\at(k,Pre), c, y));
          loop invariant (0 < \at(k,Pre)) ==> (foo86_x(\at(k,Pre), c, x));
          loop invariant (0 < \at(k,Pre)) ==> (foo86_c(\at(k,Pre), c));
          loop invariant (!(0 < \at(k,Pre))) ==> ((c == 0)&&(x == 0)&&(y == 0)&&(k == \at(k,Pre)));
          loop invariant k == \at(k,Pre);
          loop assigns c, y, x;*/
void stub_A(int k);

/*@loop invariant y == c;
    loop invariant x == y * y;
    loop invariant x == y * y * c;
    loop invariant x == c * c;
    loop invariant x == c * c * (c + 1) / 2;
    loop invariant x == \sum(0, c-1, \lambda integer t; (t+1)*(t+1));
    loop invariant c <= k;
    loop invariant 0 <= x;
    loop invariant 0 <= c;
    loop assigns y;
    loop assigns x;
    loop assigns c;*/
void stub_B(int k);

/*@loop invariant y == c;
    loop invariant x == y * y;
    loop invariant x == y * y * c;
    loop invariant x == c * c;
    loop invariant x == c * c * (c + 1) / 2;
    loop invariant x == \sum(0, c-1, \lambda integer t; (t+1)*(t+1));
    loop invariant c <= k;
    loop invariant 0 <= x;
    loop invariant 0 <= c;
    loop assigns y;
    loop assigns x;
    loop assigns c;*/
void check_A_implies_B(int k) {
    stub_A(k);
}

/*@loop invariant (0 < \at(k,Pre)) ==> (foo86_goal(\at(k,Pre), c, x, y));
          loop invariant (0 < \at(k,Pre)) ==> (foo86_y(\at(k,Pre), c, y));
          loop invariant (0 < \at(k,Pre)) ==> (foo86_x(\at(k,Pre), c, x));
          loop invariant (0 < \at(k,Pre)) ==> (foo86_c(\at(k,Pre), c));
          loop invariant (!(0 < \at(k,Pre))) ==> ((c == 0)&&(x == 0)&&(y == 0)&&(k == \at(k,Pre)));
          loop invariant k == \at(k,Pre);
          loop assigns c, y, x;*/
void check_B_implies_A(int k) {
    stub_B(k);
}
