#include <limits.h>



/*@loop invariant x == 4 * y;
      loop invariant y <= \at(y, Pre);
      loop invariant x % 4 == 0;
      loop invariant (4 * \at(y, Pre) > 0) ==> (x == 4 * y);
      loop invariant (4 * \at(y, Pre) > 0) ==> (0 <= y);
      loop invariant (4 * \at(y, Pre) > 0) ==> (0 <= x);
      loop invariant (!(4 * \at(y, Pre) > 0)) ==> ((x == 4 * \at(y, Pre)) && (y == \at(y, Pre)));
      loop assigns x, y;*/
void stub_A(int y);

/*@loop invariant x == 4 * y;
    loop assigns y;
    loop assigns x;*/
void stub_B(int y);

/*@loop invariant x == 4 * y;
    loop assigns y;
    loop assigns x;*/
void check_A_implies_B(int y) {
    stub_A(y);
}

/*@loop invariant x == 4 * y;
      loop invariant y <= \at(y, Pre);
      loop invariant x % 4 == 0;
      loop invariant (4 * \at(y, Pre) > 0) ==> (x == 4 * y);
      loop invariant (4 * \at(y, Pre) > 0) ==> (0 <= y);
      loop invariant (4 * \at(y, Pre) > 0) ==> (0 <= x);
      loop invariant (!(4 * \at(y, Pre) > 0)) ==> ((x == 4 * \at(y, Pre)) && (y == \at(y, Pre)));
      loop assigns x, y;*/
void check_B_implies_A(int y) {
    stub_B(y);
}
