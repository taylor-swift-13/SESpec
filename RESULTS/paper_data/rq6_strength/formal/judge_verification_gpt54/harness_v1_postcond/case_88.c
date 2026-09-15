#include <limits.h>


/*@
  logic integer fourth_sum(integer n) =
    n <= 0 ? 0 : fourth_sum(n - 1) + n * n * n * n;
*/

/*@loop invariant 0 <= c;
          loop invariant c == y;
          loop invariant x == fourth_sum(c);
          loop invariant (0 < \at(k,Pre)) ==> (c <= \at(k,Pre));

          loop invariant (0 < \at(k,Pre)) ==> (x == fourth_sum(c) && c == y && 0 <= c <= \at(k,Pre));
          loop invariant (0 < \at(k,Pre)) ==> (c == y);
          loop invariant (0 < \at(k,Pre)) ==> (x == fourth_sum(c));
          loop invariant (0 < \at(k,Pre)) ==> (0 <= c <= \at(k,Pre));
          loop invariant (!(0 < \at(k,Pre))) ==> ((c == 0)&&(x == 0)&&(y == 0)&&(k == \at(k,Pre)));
          loop invariant k == \at(k,Pre);
          loop assigns c, y, x;*/
void stub_A(int k);

/*@loop invariant y == c;
    loop invariant x == y*y*y*y*(c ? 1 : 0) || x >= 0;
    loop invariant x == y*y*y*y + x - (y*y*y*y);
    loop invariant x == y*y*y*y * c || x >= 0;
    loop invariant x == \sum(0, c-1, \lambda integer t; (t+1)*(t+1)*(t+1)*(t+1));
    loop invariant c <= k;
    loop invariant 0 <= x;
    loop invariant 0 <= c;
    loop assigns y;
    loop assigns x;
    loop assigns c;*/
void stub_B(int k);

/*@loop invariant y == c;
    loop invariant x == y*y*y*y*(c ? 1 : 0) || x >= 0;
    loop invariant x == y*y*y*y + x - (y*y*y*y);
    loop invariant x == y*y*y*y * c || x >= 0;
    loop invariant x == \sum(0, c-1, \lambda integer t; (t+1)*(t+1)*(t+1)*(t+1));
    loop invariant c <= k;
    loop invariant 0 <= x;
    loop invariant 0 <= c;
    loop assigns y;
    loop assigns x;
    loop assigns c;*/
void check_A_implies_B(int k) {
    stub_A(k);
}

/*@loop invariant 0 <= c;
          loop invariant c == y;
          loop invariant x == fourth_sum(c);
          loop invariant (0 < \at(k,Pre)) ==> (c <= \at(k,Pre));

          loop invariant (0 < \at(k,Pre)) ==> (x == fourth_sum(c) && c == y && 0 <= c <= \at(k,Pre));
          loop invariant (0 < \at(k,Pre)) ==> (c == y);
          loop invariant (0 < \at(k,Pre)) ==> (x == fourth_sum(c));
          loop invariant (0 < \at(k,Pre)) ==> (0 <= c <= \at(k,Pre));
          loop invariant (!(0 < \at(k,Pre))) ==> ((c == 0)&&(x == 0)&&(y == 0)&&(k == \at(k,Pre)));
          loop invariant k == \at(k,Pre);
          loop assigns c, y, x;*/
void check_B_implies_A(int k) {
    stub_B(k);
}
