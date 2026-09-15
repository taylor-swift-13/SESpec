#include <limits.h>


/*@
  logic integer pow5(integer v) = v * v * v * v * v;

  logic integer sum_pow5(integer n) =
    n <= 0 ? 0 : sum_pow5(n - 1) + pow5(n);
*/

/*@loop invariant (0 < \at(k,Pre)) ==> (x == sum_pow5(c));
      loop invariant (0 < \at(k,Pre)) ==> (y == c);
      loop invariant (0 < \at(k,Pre)) ==> (c <= k);
      loop invariant (0 < \at(k,Pre)) ==> (c >= 0);
      loop invariant (!(0 < \at(k,Pre))) ==> ((c == 0)&&(x == 0)&&(y == 0)&&(k == \at(k,Pre)));
      loop invariant k == \at(k,Pre);
      loop assigns c, y, x;*/
void stub_A(int k);

/*@loop invariant y == c;
    loop invariant x == y*y*y*y*y;
    loop invariant c <= k;
    loop invariant \exists integer t; t == c && y == t;
    loop invariant 0 <= x;
    loop invariant 0 <= c;
    loop assigns y;
    loop assigns x;
    loop assigns c;*/
void stub_B(int k);

/*@loop invariant y == c;
    loop invariant x == y*y*y*y*y;
    loop invariant c <= k;
    loop invariant \exists integer t; t == c && y == t;
    loop invariant 0 <= x;
    loop invariant 0 <= c;
    loop assigns y;
    loop assigns x;
    loop assigns c;*/
void check_A_implies_B(int k) {
    stub_A(k);
}

/*@loop invariant (0 < \at(k,Pre)) ==> (x == sum_pow5(c));
      loop invariant (0 < \at(k,Pre)) ==> (y == c);
      loop invariant (0 < \at(k,Pre)) ==> (c <= k);
      loop invariant (0 < \at(k,Pre)) ==> (c >= 0);
      loop invariant (!(0 < \at(k,Pre))) ==> ((c == 0)&&(x == 0)&&(y == 0)&&(k == \at(k,Pre)));
      loop invariant k == \at(k,Pre);
      loop assigns c, y, x;*/
void check_B_implies_A(int k) {
    stub_B(k);
}
